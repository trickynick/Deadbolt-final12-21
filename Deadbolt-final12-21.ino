#include <Servo.h>
int greenPin = 4;
int redPin = 5;
int sensorPin = A0; // zigbee sensor        
int sensorValue = 0; //int servoValue =0;// variable to store the value coming from the sensor
Servo servo;
int tranPin = 7; //relay
int locked = 0; // 0 means unlocked, 1 means locked
// servo = 9
void blinkLed(int pinNumber, int time)
{
  digitalWrite (pinNumber, HIGH);
  delay(time);
  digitalWrite (pinNumber, LOW);
  delay(time); 
}


void setup()
{
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(tranPin, OUTPUT); 
  Serial.begin(9600);
  servo.attach(9);
  
  // start with relay off
  digitalWrite(tranPin, HIGH);
  

}

void loop() {

  sensorValue = analogRead(sensorPin); 

  float voltage= sensorValue * (3.3 / 1023.0);

  if(voltage < 0.5) 
  { 
    if( locked == 1)
    {
      digitalWrite(5,LOW);
      blinkLed(4,200);
      blinkLed(4,200);
     
      digitalWrite(4, HIGH);
      digitalWrite(tranPin, LOW);
      servo.write(150);
      delay(275);
      digitalWrite(tranPin, HIGH);

    delay(2000);
    }

    locked = 0;
  }

  else
  {
    if( locked == 0)
    {
      digitalWrite(4,LOW);
      blinkLed(5,200);
      blinkLed(5,200);
      
      digitalWrite(5,HIGH);
      digitalWrite(tranPin, LOW);
      servo.write(80);
      delay(275);
      digitalWrite(tranPin, HIGH);
      delay(2000);

    }

    locked = 1;
  }
  
}


// sources..minion_itw


