#include <Servo.h>

const int pirSensorPin = 3;
const int ledPin = 6;
const int buzzerPin = 9;
const int GndPin = 5;
const int DetectionPin = 2;
const int CamActivationPin = 1;
const int ServoPin = 4;
const int GreenLED = 11;
const int RedLED = 12;

Servo myServo;

void setup(){
  pinMode(pirSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(GndPin, OUTPUT);
  digitalWrite(GndPin, LOW);
  myServo.attach(ServoPin);
  myServo.write(90);
  Serial.begin(9600);
}

void loop(){
  int pirState = digitalRead(pirSensorPin);
  
  if (pirState == HIGH){
    digitalWrite(ledPin, HIGH);
	digitalWrite(CamActivationPin, HIGH);
    Serial.println("Motion detected!");
    
    if(digitalRead(DetectionPin) == HIGH){
    	digitalWrite(buzzerPin, HIGH);
      	digitalWrite(RedLED, HIGH);
      	digitalWrite(GreenLED, LOW);
      	myServo.write(90);
    }
    else{
    	digitalWrite(buzzerPin, LOW);
      	digitalWrite(RedLED, LOW);
      	digitalWrite(GreenLED, HIGH);
      	myServo.write(0);
    }
  }
  
  else{
    digitalWrite(ledPin, LOW);
    digitalWrite(CamActivationPin, LOW);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(GreenLED, LOW);
    digitalWrite(RedLED, LOW);
    myServo.write(90);
    Serial.println("No motion.");
  }

  delay(500);
}
