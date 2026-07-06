#include <Servo.h>

Servo gateServo;

const int irPin = 2;
const int ledPin = 7;

void setup() {
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);

  gateServo.attach(9);

  // Initial position - Gate Closed
  gateServo.write(0);
  digitalWrite(ledPin, LOW);

  Serial.begin(9600);
}

void loop() {

  int sensorValue = digitalRead(irPin);

  // Most IR sensors output LOW when an object is detected
  if (sensorValue == LOW) {

    Serial.println("Vehicle Detected");
    digitalWrite(ledPin, HIGH);

    // Open the gate
    gateServo.write(90);

    // Keep gate open
    delay(3000);

    // Close the gate
    gateServo.write(0);
    digitalWrite(ledPin, LOW);

    // Wait until vehicle leaves
    while (digitalRead(irPin) == LOW) {
      delay(100);
    }

    delay(500);
  }
}