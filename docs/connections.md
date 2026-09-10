# Circuit Connections

## Components

- Arduino Uno
- 28BYJ-48 5-wire stepper motor
- ULN2003 stepper motor driver
- Servo motor
- Inductive proximity (metal) sensor
- IR sensor module
- Water/moisture sensor
- Buzzer

## Pin Connections

| Component | Pin | Arduino Uno |
|---|---|---|
| ULN2003 | IN1 | D8 |
| ULN2003 | IN2 | D9 |
| ULN2003 | IN3 | D10 |
| ULN2003 | IN4 | D11 |
| ULN2003 | VCC | 5V |
| ULN2003 | GND | GND |
| Servo | Signal (Yellow) | D6 |
| Servo | VCC (Red) | 5V |
| Servo | GND (Brown) | GND |
| Metal Sensor | OUT (Black) | D7 |
| Metal Sensor | VCC (Brown) | 5V |
| Metal Sensor | GND (Blue) | GND |
| IR Sensor | OUT | D5 |
| IR Sensor | VCC | 5V |
| IR Sensor | GND | GND |
| Moisture Sensor | AO | A0 |
| Moisture Sensor | VCC | 5V |
| Moisture Sensor | GND | GND |
| Buzzer | Positive | D4 |
| Buzzer | Negative | GND |

## Working

1. The IR sensor detects the presence of waste.
2. The inductive proximity sensor checks for metal waste.
3. Metal waste is directed toward the metal bin using the stepper and servo mechanism.
4. For non-metal waste, the moisture sensor determines whether the waste is wet or dry.
5. Wet waste is directed to the wet bin, while dry waste is directed to the dry bin.
6. The buzzer provides an audible indication during detection/sorting.

## Important

The Arduino pin assignments above match the project code. The metal sensor output is configured as active-LOW in the code, and the IR sensor is also treated as active-LOW. Verify the actual sensor module output logic before final hardware testing.
