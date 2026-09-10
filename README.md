# ♻️ Smart Waste Segregation

An automated waste segregation system that detects waste and separates it into metal, wet, and dry categories using sensors, a stepper motor, and a servo motor.

## Features

- IR-based waste detection
- Inductive proximity sensing for metal waste
- Moisture-based wet/dry classification
- Stepper motor controlled sorting gate
- Servo-controlled bin direction
- Buzzer indication
- Arduino Uno based control

## Hardware

- Arduino Uno
- 28BYJ-48 Stepper Motor
- ULN2003 Driver
- Servo Motor
- Inductive Proximity Sensor
- IR Sensor Module
- Moisture/Water Sensor
- Buzzer

## Repository Structure

```text
SMART-WASTE-SEGREGATION/
├── README.md
├── src/
│   └── smart_waste_segregation.ino
├── docs/
│   └── connections.md
└── circuit/
    └── circuit-diagram.svg
```

## Working Principle

1. The IR sensor detects the presence of waste.
2. The metal sensor checks whether the waste is metallic.
3. Metal waste is routed to the metal bin.
4. Non-metal waste is checked using the moisture sensor.
5. High moisture is classified as wet waste.
6. Low moisture is classified as dry waste.
7. The stepper and servo operate the sorting mechanism.
8. The buzzer provides an audible indication.

## Arduino Pin Summary

| Function | Arduino Pin |
|---|---|
| IR Sensor | D5 |
| Servo Signal | D6 |
| Metal Sensor | D7 |
| Stepper IN1 | D8 |
| Stepper IN2 | D9 |
| Stepper IN3 | D10 |
| Stepper IN4 | D11 |
| Buzzer | D4 |
| Moisture Sensor AO | A0 |

## Software

- Arduino IDE
- `CheapStepper` library
- `Servo` library

## Note

Verify sensor output logic and power requirements before connecting the final hardware. The uploaded code treats the metal and IR sensors as active-LOW.
