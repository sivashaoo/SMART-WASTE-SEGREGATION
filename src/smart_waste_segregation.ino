#include <CheapStepper.h>
#include <Servo.h>

// ---------------- Pin Definitions ----------------
#define IR_SENSOR      5
#define SERVO_PIN      6
#define METAL_SENSOR   7
#define BUZZER         4
#define MOISTURE_PIN   A0

// Stepper motor: ULN2003 IN1, IN2, IN3, IN4
CheapStepper stepper(8, 9, 10, 11);
Servo servo1;

// ---------------- Variables ----------------
int soil = 0;
int fsoil = 0;
int servoAng = 95;

void setup() {
  Serial.begin(9600);

  pinMode(METAL_SENSOR, INPUT_PULLUP);
  pinMode(IR_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);

  servo1.attach(SERVO_PIN);
  stepper.setRpm(17);

  // Initial servo position
  servo1.write(180);
  delay(2000);
  servo1.write(servoAng);
  delay(1000);
}

void loop() {
  fsoil = 0;

  // ---------------- Metal Detection ----------------
  // Active-LOW proximity sensor: LOW means metal detected.
  int metalState = digitalRead(METAL_SENSOR);
  Serial.print("Metal Sensor: ");
  Serial.println(metalState);

  if (metalState == LOW) {
    tone(BUZZER, 1000, 1000);

    // Move sorting mechanism toward metal bin
    stepper.moveDegreesCCW(240);
    delay(1000);

    servo1.write(180);
    delay(2000);
    servo1.write(servoAng);
    delay(1000);

    // Return sorting mechanism
    stepper.moveDegreesCW(240);
    delay(1000);
  }

  // ---------------- Waste/Object Detection ----------------
  // Common IR modules are active-LOW: LOW means object detected.
  if (digitalRead(IR_SENSOR) == LOW) {
    tone(BUZZER, 1000, 500);
    delay(1000);

    // Take three moisture readings and average them
    fsoil = 0;

    for (int i = 0; i < 3; i++) {
      soil = analogRead(MOISTURE_PIN);
      soil = constrain(soil, 485, 1023);
      fsoil += map(soil, 485, 1023, 100, 0);
      delay(75);
    }

    fsoil = fsoil / 3;

    Serial.print("Moisture: ");
    Serial.print(fsoil);
    Serial.println("%");

    // ---------------- Wet Waste ----------------
    if (fsoil > 20) {
      stepper.moveDegreesCW(240);
      delay(1000);

      servo1.write(180);
      delay(2000);
      servo1.write(servoAng);
      delay(1000);

      // Return sorting mechanism
      stepper.moveDegreesCCW(240);
      delay(1000);
    }

    // ---------------- Dry Waste ----------------
    else {
      tone(BUZZER, 1000, 500);
      delay(1000);

      servo1.write(180);
      delay(2000);
      servo1.write(servoAng);
      delay(1000);
    }
  }
}
