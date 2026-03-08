/*
  ZUMO - ROBOT DE CARRERA

  El robot avanza recto hasta detectar la línea blanca (meta).
  Cuando la detecta, se detiene completamente.

*/

#include <Wire.h>
#include <ZumoShield.h>

#define LED 13

// Sensibilidad del sensor (puede necesitar ajuste)
#define QTR_THRESHOLD 1500

// Velocidad (0 a 400)
#define FORWARD_SPEED 200

ZumoBuzzer buzzer;
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);

#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];

ZumoReflectanceSensorArray sensors(QTR_NO_EMITTER_PIN);

bool metaAlcanzada = false;

void waitForButtonAndCountDown()
{
  digitalWrite(LED, HIGH);
  button.waitForButton();
  digitalWrite(LED, LOW);

  // cuenta regresiva sonora
  for (int i = 0; i < 3; i++)
  {
    delay(1000);
    buzzer.playNote(NOTE_G(3), 200, 15);
  }

  delay(1000);
  buzzer.playNote(NOTE_G(4), 500, 15);
}

void setup()
{
  pinMode(LED, OUTPUT);

  // Descomentar si los motores giran al revés
  //motors.flipLeftMotor(true);
  //motors.flipRightMotor(true);

  waitForButtonAndCountDown();
}

void loop()
{
  if (metaAlcanzada)
  {
    motors.setSpeeds(0,0);
    return;
  }

  sensors.read(sensor_values);

  // Detectar línea blanca con sensores extremos
  if (sensor_values[0] < QTR_THRESHOLD || sensor_values[5] < QTR_THRESHOLD)
  {
    motors.setSpeeds(0,0);
    metaAlcanzada = true;

    buzzer.playNote(NOTE_G(5), 600, 15); // sonido de meta
    digitalWrite(LED, HIGH);
  }
  else
  {
    // avanzar hacia la meta
    motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
  }
}
