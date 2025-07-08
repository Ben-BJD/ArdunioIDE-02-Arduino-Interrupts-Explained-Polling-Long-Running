#include <Arduino.h>
 
#define LED_PIN 6
#define BUTTON_PIN 2
 
int ledState = LOW; // Initial state of the LED
 
void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.begin(9600);
}
 
void buttonLogic() {
  int newState = digitalRead(BUTTON_PIN);
  if(newState != ledState) {
    if(newState == HIGH) {
      Serial.println("The button is pressed.");
    } else {
      Serial.println("The button is released.");
    }
    ledState = newState;
    digitalWrite(LED_PIN, ledState);
  }
  delay(100);
}
 
// This function simulates a long, blocking task
void timeIntensiveTask() {
  Serial.println("Time intensive running ...");
  // Simulate work by looping many times
  for (long i = 0; i < 100000; i++) {
    // This loop takes a noticeable amount of time
    Serial.println("Time intensive task still running ...");
  }
  Serial.println("Time intensive task finished.");
}
 
void loop() {
  buttonLogic();
  timeIntensiveTask();
}