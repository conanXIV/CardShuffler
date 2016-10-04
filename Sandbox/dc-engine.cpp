
#include "dc-engine.h"
#include "globals.h"

void Engine::pulse()
{
  delay(1000);
  sendEngineState(engineOn);
  delay(10000);
  sendEngineState(engineOff);
}

void Engine::sendEngineState(uint8_t instruction)
{
    digitalWrite(enginePin_, instruction);
}

