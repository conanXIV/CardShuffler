#include <Arduino.h>
#include "utility.h"
#include "globals.h"
#include "dc-engine.h"
#include "step-engine.h"

LED* led;
Button* button;
StepEngine* engine;
//DCEngine* engine;

void setup()
{
    Globals* globals = Globals::getInstance();

    Serial.begin(globals->boardRate);

    // initialize the digital pin as an output.
    //pinMode(globals->outputPin, OUTPUT);
    //pinMode(globals->inputPin, INPUT);

    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);

    //led = new LED(globals->outputPin);
    //button = new Button(globals->inputPin);
    //engine = new DCEngine(globals->outputPin);
    engine = new StepEngine(8, 10, 9, 11);
}

void loop()
{
    //button->waitForButton();
    //led->ledToggle();
    /*if(button->checkButton())
    {
        led->ledToggle();
    }*/
    //engine->pulse();
    //engine->run();
}
