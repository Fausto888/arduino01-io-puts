#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class Ultrasonic
{
  public:
    Ultrasonic(int echoPin, int triggerPin);
    int getLastMeasure();
    void changePorts(int echoPin, int triggerPin);
    void changeDelays(int firstDelay, int secondDelay);
    void changeCalibrationConstant(float constant);
    void changeReadDelay(int delayUs);
  private:
    int _echoPin;
    int _triggerPin;
    int _firstDelayUs;
    int _secondDelayUs;
    float _calibrationConstant;
    int _readDelay;  
};

#endif
