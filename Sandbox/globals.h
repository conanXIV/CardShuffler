
#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

class Globals
{
public:
    // Singleton Instance
    static Globals* getInstance() { return &globalInstance; }
    // Constructor
    Globals()
    : inputPin(10), outputPin(13), boardRate(9600), delayTime(1000)
    {};
    // Members
    const int inputPin;
    const int outputPin;
    const int boardRate;
    const int delayTime;
private:
  static Globals globalInstance;
};

#endif

