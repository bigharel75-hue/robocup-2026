#include "motor.h"

#define trigPin A4
#define echoPin A3
#define BAUD_RATE 115200
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

void loop() {
  motorL.move(200);
  Serial.println("move motorL with 200");
  motorR.move(200);
  Serial.println("move motorR with 200");
  delay(100);
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
