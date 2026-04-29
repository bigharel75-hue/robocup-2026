#include "motor.h"

#define trigPin A4
#define echoPin A3
#define BAUD_RATE 9600
#define toDrive 255.0/50

#define motorL0 5
#define motorL1 9
#define motorR0 6
#define motorR1 10

#define bsR A0
#define bsR A1

motor motorL(motorL0, motorL1);
motor motorR(motorR0, motorR1);
int firstColor = 0;
int secColor = 0;
void setup() {
  pinMode(A5, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(bsR, INPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(BAUD_RATE);
  
  // Clears the Serial Monitor screen on startup/reset
  Serial.write("\033[2J"); 
  Serial.write("\033[H");

  motorL.begin();
  motorR.begin();
}

int speed = 125;
void loop() {
  if (analogRead(A5) >= 13) {
    motorL.move(speed);
    motorR.move(speed);
  }
  else {
    motorL.move(-speed);
    motorR.move(-speed);
  }
  // delay(50);
}

int readUltraSonic()
{
  long duration = 0;
  int distance = 0;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
