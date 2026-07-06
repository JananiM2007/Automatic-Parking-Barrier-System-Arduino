#include <Servo.h>

Servo gateServo;

void setup() {
  gateServo.attach(9);   // Servo signal connected to D9
}

void loop() {

  // Move to 0°
  gateServo.write(0);
  delay(2000);

  // Move to 90°
  gateServo.write(90);
  delay(2000);

  // Move to 180°
  gateServo.write(180);
  delay(2000);

}