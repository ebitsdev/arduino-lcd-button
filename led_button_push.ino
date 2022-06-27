#define LED_PIN 4
#define BUTTON_PIN 8

byte lastButtonState;
byte ledState = LOW;

void setup() {
  // set the digital pin as output:
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lastButtonState = digitalRead(BUTTON_PIN);
}

void loop(){
    byte buttonState = digitalRead(BUTTON_PIN);
    if (buttonState == LOW && lastButtonState == HIGH) {
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
    }
    lastButtonState = buttonState;
    delay(100);
}