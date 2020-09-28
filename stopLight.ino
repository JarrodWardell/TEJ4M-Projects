/*
  Simple code to turn on and off lights like a traffic light. The LEDs can have a common ground, just ensure to hook them to the right pins.
*/

int greenTime = 2; // How long it stays green
int yellowTime = 1; // How long it stays yellow
int redTime = 3; // How long it stays red

void setup() {
  pinMode(2, OUTPUT); // GREEN
  pinMode(3, OUTPUT); // YELLOW
  pinMode(4, OUTPUT); // RED
}

void loop() {
  digitalWrite(2, HIGH);
  delay(greenTime*1000); // wait for the required time
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(yellowTime*1000); // wait for the required time
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH); 
  delay(redTime*1000); // wait for the required time
  digitalWrite(4, LOW);
}
