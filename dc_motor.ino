
 
int IN1 = 3; 
int IN2 = 5; 
int IN3 = 6; 
int IN4 = 9; 
int Rv = 10;
int F = 2;
int R =7;
int L =8;
char user_input;
int s =1;
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(Rv, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(L, OUTPUT);

  Serial.begin(9600);
  Serial.println("Enter number for control option:");
  Serial.println("1. FORWARD");
  Serial.println("2. REVERSE"); 
  Serial.println("3. STOP");
  Serial.println("4. left");
  Serial.println("5. right");
}

void loop()
{
  while(Serial.available())
  {
    user_input = Serial.read();
    Stop();
    if (user_input =='1')
    {
      Stop();
      delay(500);
       Forward();
       digitalWrite(R, LOW);
      digitalWrite(L, LOW);
    }
    else if(user_input =='2')
    {
      Stop();
      delay(500);
      Reverse();
      digitalWrite(R, LOW);
      digitalWrite(L, LOW);
    }
    else if(user_input =='3')
    {
      Stop();
      
      for(int s=0;s<=10;s++)
    {
    digitalWrite(R, HIGH);
    digitalWrite(L, HIGH);
    delay(500);
    digitalWrite(R, LOW);
    digitalWrite(L, LOW);
    }
    }
    else if(user_input =='4')
    {
      Stop();
      delay(500);
      right();
      digitalWrite(R, LOW);
      digitalWrite(L, LOW);

    }
    else if(user_input =='5')
    {
      Stop();
      delay(500);
      left();
      digitalWrite(R, LOW);
      digitalWrite(L, LOW);

    }
else if(user_input =='6')
    {
      Stop();
      delay(100);
      Forward();
      delay(100);
      digitalWrite(R, LOW);
      digitalWrite(L, LOW);
       right();
      delay(100);
      digitalWrite(R, LOW);
      digitalWrite(L, LOW);
      Forward();
      delay(100);
      digitalWrite(R, LOW);
      digitalWrite(L, LOW);

    }
    
  }
}


void Reverse()
{ 
  digitalWrite(Rv, HIGH);
  analogWrite(IN1, 0);
  analogWrite(IN2, 100);
  analogWrite(IN3, 100);
  analogWrite(IN4, 0);
  
  Serial.print("Car Forward");
  Serial.println();
}

void Forward()
{
  digitalWrite(F, HIGH);
  analogWrite(IN1, 100); 
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 100);
  Serial.print("Car Reverse");
  Serial.println();
}

void Stop()
{
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0);
    digitalWrite(F, LOW);
    digitalWrite(Rv, LOW);
    Serial.print("Car Stop");
    Serial.println();
    
}
void sStop()
{
  for(int s=0;s<=10;s++)
    {
    digitalWrite(R, HIGH);
    digitalWrite(L, HIGH);
    delay(200);
    digitalWrite(R, LOW);
    digitalWrite(L, LOW);
    }
}
void right()
{
  analogWrite(IN1, 100); 
  analogWrite(IN2, 0);
  analogWrite(IN3, 100);
  analogWrite(IN4, 0);
  Serial.print("Car right");
  Serial.println();
  for(int s=0;s<=10;s++)
    {
  digitalWrite(R, HIGH);
  delay(100);
  digitalWrite(R, LOW);
    }
}
void left()
{
  analogWrite(IN1, 0); 
  analogWrite(IN2, 100);
  analogWrite(IN3, 0);
  analogWrite(IN4, 100);
  Serial.print("Car left");
  Serial.println();
  for(int s=0;s<=10;s++)
    {
  digitalWrite(L, HIGH);
  delay(100);
  digitalWrite(L, LOW);
  
}}
