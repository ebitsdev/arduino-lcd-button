//If you use different socket numbers update them below
#include <Wire.h>
#include "rgb_lcd.h"
#define buttonPin 8
#define ledPin 4

/* Learn to use pushbutton (button switch) with Arduino - Tutorial
   More info and circuit schematic: http://www.ardumotive.com/arduino-tutorials/category/button
   Dev: Michalis Vasilakis / Date: 19/10/2014
   UPDATED 2/6/2016 - LED to Arduino pin 3 and button to Arduino pin 4*/

//Variables
rgb_lcd lcd;
int buttonState = 0;
int flag = 0;
int delayTime = 100;
int flashingTime = 500;

void setup() {
  //Input or output?
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.begin(16, 2);
  //  lcd.setRGB(colorR, colorG, colorB);
}

void loop() {
  //Read button state (pressed or not pressed?)
  buttonState = digitalRead(buttonPin);

  //If button pressed...
  if (buttonState == HIGH) {
    //...ones, turn led on!
    if ( flag == 0) {
      digitalWrite(ledPin, HIGH);
      // Change LCD RGB Colors
      for (int i = 0; i < 255; i++) {
        lcd.setRGB(255, 0, 0);
        delay(5);
      }
      for (int i = 0; i < 255; i++) {
        lcd.setRGB(0, 0, 255);
        delay(5);

      }
      for (int i = 0; i < 255; i++) {
        lcd.setRGB(0, 255 - i, i);
        delay(5);
      }
      lcd.print("This is working");
      flag = 1; //change flag variable
    }
    //...twice, turn led off!
    else if ( flag == 1) {
      digitalWrite(ledPin, LOW);
      lcd.begin(16, 2);
      flag = 0; //change flag variable again
    }
  }
  delay(200); //Small delay

}