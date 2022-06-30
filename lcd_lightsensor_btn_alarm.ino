#include <Wire.h>
#include "rgb_lcd.h"

#define lightSensorSocket A0
#define buttonSocket 8
#define buzzerSocket 7

rgb_lcd lcd;
const int colorR = 0;
const int colorG = 0;
const int colorB = 0;
int delayTime = 200;
int lowTrigger = 250;  //<- Change to YOUR measured value
int highTrigger = 300; //<- Change to YOUR measured value
int lightAmount;
int state;

void setup() {
  pinMode(buttonSocket, INPUT);
  pinMode(buzzerSocket, OUTPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  clearScreen();
}
void loop() {
  // put your main code here, to run repeatedly:


  lightAmount = analogRead(lightSensorSocket);
  if (lightAmount < lowTrigger) {
    state = 1;
  } if (lightAmount > highTrigger) {
    state = 0;
  }

  if (state) {
    lcd.setRGB(255 , 0, 0);
    delay(delayTime);
    lcd.setRGB(0 , 255, 0);
    delay(delayTime);
    lcd.setRGB(0 , 0, 255);
  } else {
    lcd.setRGB(0 , 0, 0);
  }

  delay(delayTime);
  if (digitalRead(buttonSocket)) {
    digitalWrite(buzzerSocket, HIGH);
    delay(500);
    digitalWrite(buzzerSocket, LOW);
  } else {
    digitalWrite(buzzerSocket, LOW);
  }
}

void clearScreen() {
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}