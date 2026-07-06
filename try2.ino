#include <Servo.h>

Servo gateServo;

const int irPin = 2;
const int ledPin = 7;

bool gateOpen = false;

void setup() {
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);

  gateServo.attach(9);
  gateServo.write(0);      // Gate Closed

  Serial.begin(9600);
}

void loop() {

  int sensor = digitalRead(irPin);

  // Vehicle detected
  if (sensor == LOW && !gateOpen) {

    Serial.println("Vehicle Detected");
    gateServo.write(180);
    digitalWrite(ledPin, HIGH);

    gateOpen = true;
  }

  // Vehicle has left
  if (sensor == HIGH && gateOpen) {

    delay(1000);   // Wait 1 second

    // Check again to avoid false detection
    if (digitalRead(irPin) == HIGH) {

      Serial.println("Vehicle Passed");

      gateServo.write(0);
      digitalWrite(ledPin, LOW);

      gateOpen = false;
    }
  }
}