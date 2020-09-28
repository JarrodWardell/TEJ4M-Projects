/*
  Simple code to blink an LED without using the Delay() function.
*/

double delayTime = 1.0; // The time (in seconds) to flash the light
int lightPin = 2; // The pin the light will be using to flash
unsigned long startTime = 0; // Used to check time

void setup() {
  startTime = millis(); // Set startTime to time
  pinMode(lightPin, OUTPUT); //Prep pin
}

void loop() {
  if (millis() - startTime >= delayTime * 1000 || millis() < startTime) { // Check if the difference between the last loop and now is greater than delay time or if millis is less than startTime (it overflowed)
    digitalWrite(lightPin, !digitalRead(lightPin)); // Set the light to what it is not
    startTime = millis(); // Change the start time
  }
}
