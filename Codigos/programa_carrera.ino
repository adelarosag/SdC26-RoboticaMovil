/*
PROGRAMA - CARRERA

Este programa hace que el robot se diriga hacia adelante a una velocidad
predeterminada.

*/

#include <Wire.h>
#include <ZumoShield.h>

#define LED_PIN 13

ZumoMotors motors;

// Velocidad a la que se moverá el Robot

int velocidad = 200;

// Tiempo de Carrera (5000 ms = 5 s)

int tiempoCarrera = 5000;

void carrera(int velocidad, int tiempo)
{
  motors.setLeftSpeed(velocidad);
  motors.setRightSpeed(velocidad);

  digitalWrite(LED_PIN, HIGH);

  delay(tiempo);

  detener();
}


void setup()
{
  pinMode(LED_PIN, OUTPUT);

  // Si alguna oruga gira al revés, descomentar:
  //motors.flipLeftMotor(true);
  //motors.flipRightMotor(true);
}

void loop()
{
  carrera(velocidad, tiempoCarrera);
}
