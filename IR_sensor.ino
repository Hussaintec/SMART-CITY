#include <Servo.h>

Servo myservo;

int IRSensor1=27; 
int LED1 =26; 
int IRSensor2 =29; 
int LED2 =28; 
int IRSensor3 =31; 
int LED3 =30;
int IRSensor4 =33; 
int LED4 =32;
int IRSensor5 =35; 
int LED5 =34;
int IRSensor6 =37; 
int LED6 =36;

int echoPin =2; 
int trigPin =3;
int pump =48;/////////pump

int park =46; /////////////park
int day =23; ////////////////day
int nod1 =10;
int P =50;
long duration; 
int distance;
int val = 0;




void setup() 
{
 
  pinMode (IRSensor1, INPUT);
  pinMode (LED1, OUTPUT);
  pinMode (IRSensor2, INPUT);
  pinMode (LED2, OUTPUT);
  pinMode (IRSensor3, INPUT);
  pinMode (LED3, OUTPUT);
  pinMode (IRSensor4, INPUT);
  pinMode (LED4, OUTPUT);
  pinMode (IRSensor5, INPUT);
  pinMode (LED5, OUTPUT);
  pinMode (IRSensor6, INPUT);
  pinMode (LED6, OUTPUT);
  myservo.attach(12);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(pump, INPUT);
  pinMode (nod1, OUTPUT);
  digitalWrite(nod1, LOW);
  pinMode (P, OUTPUT);
  digitalWrite(P, HIGH);

  pinMode(park, INPUT);
  pinMode(day,INPUT);
  Serial.begin(9600);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
 myservo.write(90); 
}

void loop()
{
   if (digitalRead(day)==HIGH)
  {
    int statusSensor1 = digitalRead (IRSensor1);
  int statusSensor2 = digitalRead (IRSensor2);
  int statusSensor3 = digitalRead (IRSensor3);
  int statusSensor4 = digitalRead (IRSensor4);
  int statusSensor5 = digitalRead (IRSensor5);
  int statusSensor6 = digitalRead (IRSensor6);
  
  if (statusSensor1 == HIGH)
    {digitalWrite(LED1, LOW); 
    Serial.println("LED1");}
  
  if  (statusSensor1 == LOW)
  {digitalWrite(LED1, HIGH);
  Serial.println("LED1");} 
  
  if  (statusSensor2 == HIGH)
    {digitalWrite(LED2, LOW);
    Serial.println("LED1");}
  
   if (statusSensor2 == LOW)
  {digitalWrite(LED2, HIGH);} 
  
   if (statusSensor3 == HIGH)
    {digitalWrite(LED3, LOW); }
  
   if (statusSensor3 == LOW)
  {digitalWrite(LED3, HIGH); }

  
   if (statusSensor4 == HIGH)
    {digitalWrite(LED4, LOW);
      Serial.println("LED1");}
  
   if (statusSensor4 == LOW)
  {digitalWrite(LED4, HIGH);}

  
   if (statusSensor5 == HIGH)
    {digitalWrite(LED5, LOW);
      Serial.println("LED1");}
  
  if (statusSensor5 == LOW)
  {digitalWrite(LED5, HIGH); }

  
   if (statusSensor6 == HIGH)
    {digitalWrite(LED6, LOW); 
      Serial.println("LED1");}
  
   if (statusSensor6 == LOW)
  {digitalWrite(LED6, HIGH); }}
  
  ///////////////////////
   if (digitalRead(day)==LOW)
  {
    int statusSensor1 = digitalRead (IRSensor1);
  int statusSensor2 = digitalRead (IRSensor2);
  int statusSensor3 = digitalRead (IRSensor3);
  int statusSensor4 = digitalRead (IRSensor4);
  int statusSensor5 = digitalRead (IRSensor5);
  int statusSensor6 = digitalRead (IRSensor6);
  
  if (statusSensor1 == HIGH)
    {digitalWrite(LED1, LOW); 
    Serial.println("LED1");}
  
  if  (statusSensor1 == LOW)
  {digitalWrite(LED1, LOW);
  Serial.println("LED1");} 
  
  if  (statusSensor2 == HIGH)
    {digitalWrite(LED2, LOW);
    Serial.println("LED1");}
  
   if (statusSensor2 == LOW)
  {digitalWrite(LED2, LOW);} 
  
   if (statusSensor3 == HIGH)
    {digitalWrite(LED3, LOW); }
  
   if (statusSensor3 == LOW)
  {digitalWrite(LED3, LOW); }

  
   if (statusSensor4 == HIGH)
    {digitalWrite(LED4, LOW);
      Serial.println("LED1");}
  
   if (statusSensor4 == LOW)
  {digitalWrite(LED4, LOW);}

  
   if (statusSensor5 == HIGH)
    {digitalWrite(LED5, LOW);
      Serial.println("LED1");}
  
  if (statusSensor5 == LOW)
  {digitalWrite(LED5, LOW); }

  
   if (statusSensor6 == HIGH)
    {digitalWrite(LED6, LOW); 
      Serial.println("LED1");}
  
   if (statusSensor6 == LOW)
  {digitalWrite(LED6, LOW); }
  ///////////////////////
  } 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
   Serial.println(distance);
  

//////////////////

    if (distance <= 1)
    {digitalWrite(nod1, HIGH); }
  
   if (distance >= 3)
  {digitalWrite(nod1, LOW); 
    Serial.println("LED1");}

//////////////////////

  if (digitalRead(pump)==HIGH)
    {digitalWrite(P, LOW); }
  
   if (digitalRead(pump)==LOW)
  {digitalWrite(P, HIGH); }  

if (digitalRead(park)==HIGH)
    {Serial.println("servoon pin7");
      
      myservo.write(180); }
  
   if (digitalRead(park)==LOW)
  { Serial.println("servooff pin7");
    myservo.write(90); }  
}
