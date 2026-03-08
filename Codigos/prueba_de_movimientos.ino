/*
PRUEBA DE MOVIMIENTOS 

Cada robot, por sus actuadores, posee diferentes configuraciones de movimiento. 
Este codigo es para mostrar como diferentes accionamientos de los motores,
genera diferentes movimientos en el robot en si. 
*/

#include <Wire.h>
#include <ZumoShield.h>

#define LED_PIN 13

ZumoMotors motors;

// Estas variables son modificables. Se pueden editar, siendo el maximo de 400

int velocidadAvanzar = 200;
int velocidadGiro = 200;

// Tiempo o delays en el que se realiza la funcion (En milisegundos, 1000 ms = 1 s)

int tiempoAvanzar = 2000;
int tiempoRetroceder = 2000;
int tiempoGiro = 1500;
int tiempoArco = 2000;


void avanzar(int velocidad, int tiempo)
{
  motors.setLeftSpeed(velocidad);
  motors.setRightSpeed(velocidad);

  digitalWrite(LED_PIN, HIGH);

  delay(tiempo);

  detener();
}

void retroceder(int velocidad, int tiempo)
{
  motors.setLeftSpeed(-velocidad);
  motors.setRightSpeed(-velocidad);

  digitalWrite(LED_PIN, LOW);

  delay(tiempo);

  detener();
}

void girarDerecha(int velocidad, int tiempo)
{
  motors.setLeftSpeed(velocidad);
  motors.setRightSpeed(-velocidad);

  delay(tiempo);

  detener();
}

void girarIzquierda(int velocidad, int tiempo)
{
  motors.setLeftSpeed(-velocidad);
  motors.setRightSpeed(velocidad);

  delay(tiempo);

  detener();
}

void arcoDerecha(int velocidad, int tiempo)
{
  motors.setLeftSpeed(velocidad);
  motors.setRightSpeed(0);

  delay(tiempo);

  detener();
}

void arcoIzquierda(int velocidad, int tiempo)
{
  motors.setLeftSpeed(0);
  motors.setRightSpeed(velocidad);

  delay(tiempo);

  detener();
}

void detener()
{
  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
  delay(1000);
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
  avanzar(velocidadAvanzar, tiempoAvanzar);

  retroceder(velocidadAvanzar, tiempoRetroceder);

  girarDerecha(velocidadGiro, tiempoGiro);

  girarIzquierda(velocidadGiro, tiempoGiro);

  arcoDerecha(velocidadGiro, tiempoArco);

  arcoIzquierda(velocidadGiro, tiempoArco);
}
