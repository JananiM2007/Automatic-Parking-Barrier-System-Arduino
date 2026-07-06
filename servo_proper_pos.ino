#include <Servo.h>

Servo gateServo;

void setup() {
  gateServo.attach(9);

  // Move to your desired starting position
  gateServo.write(0);
}

void loop() {
}