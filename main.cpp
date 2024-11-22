#include <Arduino.h>
const int buttonPin = 2;
const int redPin=8;
const int yellowPin =9;
const int greenPin =10;
void updateTrafficLights();

// put function declarations here:
int buttonState=0;
int lastButtonState =0;
int trafficState=0;
unsigned long lastDebouncetime =0;
const unsigned long debounceDelay =50;

void setup() {
  // put your setup code here, to run once:
 pinMode(redPin,OUTPUT);
 pinMode(yellowPin,OUTPUT);
 pinMode(greenPin,OUTPUT);

 pinMode(buttonPin,INPUT);
 digitalWrite(redPin,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
  lastDebouncetime=millis();
  }
  if ((millis() - lastDebouncetime) > debounceDelay) {
    if (reading != buttonState) { 
      buttonState = reading;

      if (buttonState == HIGH) {
        trafficState = (trafficState + 1 ) % 3;
        updateTrafficLights();

      }
    }
  }
  lastButtonState = reading;
}
void updateTrafficLights() {
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);

  switch (trafficState) {
    case 0: 
     digitalWrite(redPin,HIGH);
     break;
    case 1:
    digitalWrite(greenPin, HIGH);
     break;
    case 2:
    digitalWrite(yellowPin, HIGH);
     break;
  }
}

  
