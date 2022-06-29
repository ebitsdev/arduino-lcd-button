//If you use different socket numbers update them below
#include <Servo.h>
//Change here if you're using a different socket
#define servoSocket 6 //<- digital socket number
#define ledSocket 2
#define lightSensorSocket A0

Servo robotServo;
int lowTrigger = 60;  //<- Change to YOUR measured value
int highTrigger = 580; //<- Change to YOUR measured value
int lightAmount;
int state;


int pos = 0;
int servoSpeed = 5;

void setup()
{
  robotServo.attach(servoSocket);
  pinMode(ledSocket, INPUT);
}

void loop()
{
  lightAmount = analogRead(lightSensorSocket);
  if (lightAmount < lowTrigger) {
    state = 1;
  } if (lightAmount > highTrigger) {
    state = 0;
  }

  if (state) {
    for (pos = 0; pos <= 180; pos += 1) {
    // in steps of 1 degree
    robotServo.write(pos);
    delay(servoSpeed);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    robotServo.write(pos);
    delay(servoSpeed);
  }
  } else {
    robotServo.write(0);
  }
}