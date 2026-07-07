#include <Servo.h>

Servo gateServo;

// Pin Definitions
const int irPin = 2;
const int ledPin = 7;
const int servoPin = 9;

// Servo Angles
const int CLOSED_ANGLE = 0;
const int OPEN_ANGLE = 150;

// Gate Status
bool gateOpen = false;

void setup() {

  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  gateServo.attach(servoPin);

  // Keep gate closed at startup
  gateServo.write(CLOSED_ANGLE);
  digitalWrite(ledPin, LOW);

  Serial.println("Parking Barrier System Ready");
}

void loop() {

  int sensor = digitalRead(irPin);

  // ===========================
  // Vehicle Detected
  // ===========================
  if (sensor == LOW && !gateOpen) {

    Serial.println("Vehicle Detected");
    digitalWrite(ledPin, HIGH);

    gateServo.write(OPEN_ANGLE);

    gateOpen = true;
  }

  // ===========================
  // Vehicle Left
  // ===========================
  if (sensor == HIGH && gateOpen) {

    delay(1000);   // Wait 1 second to confirm vehicle has passed

    // Check again to avoid false triggering
    if (digitalRead(irPin) == HIGH) {

      Serial.println("Vehicle Passed");

      gateServo.write(CLOSED_ANGLE);
      digitalWrite(ledPin, LOW);

      gateOpen = false;
    }
  }

}