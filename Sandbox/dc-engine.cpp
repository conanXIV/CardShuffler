
#include "dc-engine.h"
#include "globals.h"

void DCEngine::pulse()
{
  delay(1000);
  sendEngineState(engineOn);
  delay(10000);
  sendEngineState(engineOff);
}

void DCEngine::sendEngineState(uint8_t instruction)
{
    digitalWrite(enginePin_, instruction);
}

