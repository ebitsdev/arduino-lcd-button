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

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.begin(16, 2);
  //set lcd brightness to 0 (turn it off)
  lcd.setRGB(0, 0, 0);
}

void loop() {
  //Read button state (pressed or not pressed)
  buttonState = digitalRead(buttonPin);

  //If button pressed...
  if (buttonState == HIGH) {
    //...ones, turn led on!
    if ( flag == 0) {
      digitalWrite(ledPin, HIGH);
      // Set LCD color to blue
      lcd.setRGB(0, 0, 255);
      //Wait for a second
      delay(1000);
      // Set LCD color to red
      lcd.setRGB(255, 0, 0);
      //Wait for a second
      delay(1000);
      // Set LCD color to blue
      lcd.setRGB(0, 0, 255);
      //Wait for a second
      delay(1000);
      lcd.setRGB(255, 0, 0);
      lcd.clear();
      flag = 1; //change flag variable
    }
    //...twice, turn led off!
    else if ( flag == 1) {
      digitalWrite(ledPin, LOW);
      //turn off lcd      
      lcd.setRGB(0, 0, 0);
      flag = 0; //change flag variable again
    }
  }
  delay(200); //Small delay
}