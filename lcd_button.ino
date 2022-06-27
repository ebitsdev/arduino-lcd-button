//If you use different socket numbers update them below
#include <Wire.h>
#include "rgb_lcd.h"

#define buttonSocket 3
#define ledSocket 8

rgb_lcd lcd;
const int colorR = 0;
const int colorG = 0;
const int colorB = 0;
int delayTime = 100;

//int i;
//int fadeTime = 8;

void setup()
{
  pinMode(buttonSocket, INPUT);
  pinMode(ledSocket, OUTPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  clearScreen();
}

void loop()
{

 if (digitalRead(buttonSocket)) {
    digitalWrite(ledSocket,HIGH);
     lcd.setRGB(175 , 100, 65);
  delay(delayTime);
  lcd.setRGB(0 , 255, 0);
  delay(delayTime);
  lcd.setRGB(0 , 0, 255);
  delay(delayTime);
//    delay(fadeTime);
  } else {
    digitalWrite(ledSocket, LOW);
  }
    
  } 
  void clearScreen() {
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}