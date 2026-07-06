# 🚗 Automatic Parking Barrier System using Arduino Uno

## 📌 Overview

This project demonstrates an automatic parking barrier system built using an Arduino Uno, an IR obstacle sensor, and an SG90 micro servo motor.

When a vehicle approaches the IR sensor, the servo rotates to open the barrier gate. The gate remains open while the vehicle is detected and automatically closes after the vehicle has passed.

This project showcases the basics of embedded systems, sensor interfacing, and servo motor control.

---

## 🛠️ Components Used

- Arduino Uno
- SG90 9g Servo Motor
- IR Obstacle Sensor
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires

---

## ⚙️ Features

- Automatic vehicle detection using an IR sensor
- Servo-controlled barrier gate
- LED status indication
- Automatic gate closing after vehicle passage
- Simple and modular Arduino code

---

## 🔌 Circuit Connections

### Servo Motor

| Servo Pin | Arduino |
|-----------|----------|
| VCC | 5V |
| GND | GND |
| Signal | D9 |

### IR Sensor

| IR Pin | Arduino |
|--------|----------|
| VCC | 5V |
| GND | GND |
| OUT | D2 |

### LED

| LED | Arduino |
|-----|----------|
| Anode (+) | D7 (through 220Ω resistor) |
| Cathode (-) | GND |

---

## 🚦 Working Principle

1. The gate starts in the closed position.
2. The IR sensor detects an approaching vehicle.
3. The servo rotates to open the barrier.
4. The gate remains open while the vehicle is present.
5. Once the vehicle passes, the barrier automatically closes.
6. The LED indicates the gate status.

---

## 💡 Applications

- Parking lots
- Residential gate automation
- Toll gate prototypes
- Smart city demonstrations
- Embedded systems learning

---

