
#ifndef DC_ENGINE_H
#define DC_ENGINE_H

#include <Arduino.h>

class Engine
{
public:
    Engine(int enginePin)
    : enginePin_(enginePin), delayTime_(10), engineOn(HIGH), engineOff(LOW), engineState_(LOW) {};

    void pulse();

private:
    const uint8_t engineOn;
    const uint8_t engineOff;
    const int delayTime_;
    const int enginePin_;
    uint8_t engineState_;    

    void sendEngineState(uint8_t instruction);
};

#endif
