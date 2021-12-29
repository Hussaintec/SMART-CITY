 #include <ESP8266WiFi.h>
 #include "DHT.h"        // DHT11 temperature and humidity sensor Predefined library
 
#define DHTTYPE DHT11   // DHT 11
#define dht_dpin 0      //GPIO-0 D3 pin of nodemcu

int Raw = A0;      //Analog channel A0 as used to measure temperature
int threshold = D0;      //Nodemcu digital pin water sensor read-GPIO16---D0 of NodeMCU
int Solenoid = D8;       // GPIO13---D7 of NodeMCU--Motor connection
int day = D2;        // GPIO13---D8 of NodeMCU--Motor connection
int park = D6;
int trash = D5;        // GPIO13---D8 of NodeMCU--Motor connection

const char* ssid = "Abu saif";
const char* password = "J0500278898";

String output0State = "off";
String output1State = "off";
DHT dht(dht_dpin, DHTTYPE); 
WiFiServer server(80);

void setup(void)
{ 
  dht.begin();
  Serial.begin(115200);
  delay(10);
  pinMode(threshold,INPUT_PULLUP); //Pin#13 as output-Activate pullup at pin 13
  pinMode(Solenoid, OUTPUT);       //D7 as output
  pinMode(day, OUTPUT);
  pinMode(trash, INPUT);
  digitalWrite(Solenoid, HIGH);     //Deactivate Solenoid
  digitalWrite(day, LOW);
  // Connect to WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);     //Begin WiFi
 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address on serial monitor
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");    //URL IP to be typed in mobile/desktop browser
  Serial.print(WiFi.localIP());
  Serial.println("/");
}



void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  } 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

 float h =0.0;  //Humidity level
 float t =0.0;  //Temperature in celcius 
 float f =0.0;  //Temperature in fahrenheit
 float percentage = 0.0; // Calculating percentage of moisture
 float reading    = 0.0; //Analog channel moisture read
 
  // Match the request
  int value = LOW;
  int value1 = LOW;
  int value2 = LOW;
  int value3 = LOW;
  if (request.indexOf("/Up=ON") != -1)  {
     h = dht.readHumidity();    //Read humidity level
     t = dht.readTemperature(); //Read temperature in celcius
     f = (h * 1.8) + 32;        //Temperature converted to Fahrenheit
     reading = analogRead(Raw); //Analog pin reading output voltage by water moisture rain sensor
     percentage = (reading/1024) * 100;   //Converting the raw value in percentage   
     value3 = digitalRead(trash);
  }

  if (request.indexOf("/Solenoid=ON") != -1)  {   //Motor ON
    digitalWrite(Solenoid, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/Solenoid=OFF") != -1)  {  //Motor OFF
    digitalWrite(Solenoid, LOW);
    value = LOW;
  }
 if (request.indexOf("/day=ON") != -1)  {   //day ON
    digitalWrite(day, LOW);
    value1 = LOW;
  }
  if (request.indexOf("/day=OFF") != -1)  {  //day OFF
    digitalWrite(day, HIGH);
    value1 = HIGH;
  }
  ////////////
  if (request.indexOf("/park=ON") != -1)  {   //park ON
    digitalWrite(park, LOW);
    value2 = LOW;
  }
  if (request.indexOf("/park=OFF") != -1)  {  //park OFF
    digitalWrite(park, HIGH);
    value2 = HIGH;
  }
  //////////////////

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE html><html>");
  client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  client.println("<link rel=\"icon\" href=\"data:,\">");
  client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
  client.println(".button { background-color: #195B6A; border: none; color: white; padding: 8px 50px;");
  client.println("text-decoration: none; font-size: 15px; margin: 1px; cursor: pointer;}");
  client.println(".button2 {background-color: #77878A;}</style></head>");
  client.println("<body><h1>Smart City Project</h1>");
  client.print("Temperature in Celsius =");
  client.println(t);
  client.println("<br>");
  client.print("Humidity =");
  client.println(h);
  client.print(" %");   
  client.println("<br>");  
  client.println();
  client.print("Moisture Level Percentage =");
  client.print(percentage);
  client.print("%");
  client.print("trash level =");
  client.print(value3);
  client.print("%");
  
  if(digitalRead(threshold)==HIGH){ // Read digital output of soil sensor
  client.println("Threshold Reached = Rain detected / Moisture exceeded / Water detected");
  }
  
  client.println("<br><br>");
  if(value == HIGH) 
    client.println("Motor/Pump Operational");
   else 
    client.print("Motor/Pump at Halt");
  
  client.println("<br><br>");
  client.println("<a href=\"/Up=ON\"\"><button>Update = Temperature  Humidity Moisture Values</button></a><br />"); 
  client.println("<a href=\"/Solenoid=ON\"\"><button>Motor Pump On </button></a>");
  client.println("<a href=\"/Solenoid=OFF\"\"><button>Motor Pump Off </button></a><br />");
  
  if(value1 == HIGH) 
    client.println("NIGH");
   else 
    client.print("DAY");
  
  client.println("<br><br>");
  client.println("<a href=\"/day=ON\"\"><button>Day </button></a>");
  client.println("<a href=\"/day=OFF\"\"><button>Night </button></a><br />");
  ///////
  if(value2 == HIGH) 
    client.println("Park_open");
   else 
    client.print("Park_close");
  
  client.println("<br><br>");
  client.println("<a href=\"/park=ON\"\"><button>Park_open</button></a>");
  client.println("<a href=\"/park=OFF\"\"><button>Park_close</button></a><br />");
  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
