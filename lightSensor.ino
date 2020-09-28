/*
Arduino Light Level Display
SETUP:
  The lights can all ground to the same pin. I use a B10k pot for the resistor after the lights and before the ground, but any resistor should do depending on the brightness you'd like.
  They should all be powered by Digital pins, which can be entered into the lightPins array. Be sure to update the lights variable to the proper amount of lights.
  The CBS should come out of 5V+. The other leg should connect to an analog pin, and that same analog pin should be connected to a ground with a 10k resistor. Using the same resistor or ground as your lights may cause interference as it did on the first iteration for mine, so avoid it.
DESCRIPTION:
  A very simple Arduino project using basics found in a Kuman Kit. It will toggle on or off lights based on how much light is hitting the CBS, with 6 being "holy heck it's bright" and 0 being pitch black.
Jarrod Wardell, September 25th, 2020
*/

int analogPin = A0; // Pin for reading voltage (Voltage is technically 5v on a scale from 0 to 1024);
int lightPins[] = {2, 3, 4, 5, 6, 7}; // Pins for Voltage (brightness) display
int lights = 6; // How many lights are being used to display.
int val = 0; // Value of the Analog pin read
int prevVals[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Last 10 Values of the Analog Pin

void setup() {
  Serial.begin(9600); // Begin Serial Output
  for (int pos = 0; pos <= lights - 1; pos++) {
    pinMode(lightPins[pos], OUTPUT); // Prepare Light Pins
    digitalWrite(lightPins[pos], LOW); // Turn off to start
  }
}

void loop() {
  val = analogRead(analogPin); // Current value
  //Serial.println(val);
  for (int a = 0; a <= 8; a++) {
    prevVals[a] = prevVals[a+1]; // Shift array by 1;
  }
  prevVals[9] = val;
  val = 0;
  for (int a = 0; a <= 9; a++) {
    val = val + prevVals[a];
  }
  double val2 = val / 10; // Last 10 Average
  //Serial.print("Last 10 Average Total: ");
  //Serial.println(val2);
  int val = round((val2/1024)*lights); // Check how many lights should be on.
  //Serial.print(val);
  //Serial.println(" Lights should be on.");
  for (int a = 0; a <= lights - 1; a++) { // RESET PINS
    digitalWrite(lightPins[a], LOW);
  }
  for (int a = 1; a <= val; a++) { // Flip on pins to display brightness
    digitalWrite(lightPins[a - 1], HIGH);
  }
}
