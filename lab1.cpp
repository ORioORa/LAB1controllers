#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
   pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    // Turn the LED on
  digitalWrite(LED_BUILTIN, HIGH);
  // Wait for half a second (1500 milliseconds)
  delay(200);

  // Turn the LED off
  digitalWrite(LED_BUILTIN, LOW);
  // Wait for another half a second
  delay(200);

}

