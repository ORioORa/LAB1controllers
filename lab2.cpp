#include <Arduino.h>

int buttonPin = 2;
int ledPin = 13;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState = digitalRead(buttonPin);

if (buttonState == LOW) {
  digitalWrite(ledPin, HIGH);
  Serial.println("Button pressed, LED ON");
} else {
  digitalWrite(ledPin, LOW);
  Serial.println("Button not pressed, LED OFF");
}
delay(100);
}

