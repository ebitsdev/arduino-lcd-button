#include <Servo.h>

//Change here if you're using a different socket
#define servoSocket 6 //<- digital socket number

Servo robotServo;

int pos = 0;
int servoSpeed = 5;

void setup() {
  robotServo.attach(servoSocket);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {
    // in steps of 1 degree
    robotServo.write(pos);
    delay(servoSpeed);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    robotServo.write(pos);
    delay(servoSpeed);
  }
}