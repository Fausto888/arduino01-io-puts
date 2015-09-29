#include "Arduino.h"
#include "Ultrasonic.h"


Ultrasonic::Ultrasonic(int echoPin, int triggerPin)
{
  _echoPin = echoPin;
  _triggerPin = triggerPin;
  _firstDelayUs = 5;
  _secondDelayUs = 10;
  _calibrationConstant = 0.017;
  _readDelay = 1000; 
  pinMode(_triggerPin, OUTPUT);
  pinMode(_echoPin, INPUT); 
}

int Ultrasonic::getLastMeasure()
{
  int distancia;
  int tiempo;

  digitalWrite(_triggerPin, LOW);
  delayMicroseconds(_firstDelayUs);
  digitalWrite(_triggerPin, HIGH);
  delayMicroseconds(_secondDelayUs);
  tiempo=pulseIn(_echoPin, HIGH);
  distancia= int(_calibrationConstant*tiempo);
  delay(_readDelay);
  return distancia;
}

void Ultrasonic::changePorts(int echoPin, int triggerPin)
{
  _echoPin = echoPin;
  _triggerPin = triggerPin;
 
  pinMode(_triggerPin, OUTPUT);
  pinMode(_echoPin, INPUT); 
}

void Ultrasonic::changeDelays(int firstDelay, int secondDelay)
{
  _firstDelayUs = firstDelay;
  _secondDelayUs = secondDelay;
}

void Ultrasonic::changeCalibrationConstant(float constant)
{
  _calibrationConstant = constant; 
}

void Ultrasonic::changeReadDelay(int delayUs)
{
  _readDelay = delayUs; 
}
