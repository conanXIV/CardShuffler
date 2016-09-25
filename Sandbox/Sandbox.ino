#include <Arduino.h>
#include "utility.h"
#include "globals.h"

LED* led;
Button* button;

void setup()
{
    Globals* gloabls = Globals::getInstance();

    Serial.begin(gloabls->boardRate);

    // initialize the digital pin as an output.
    pinMode(gloabls->outputPin, OUTPUT);
    pinMode(gloabls->inputPin, INPUT);

    led = new LED(gloabls->outputPin);
    button = new Button(gloabls->inputPin);
}

void loop()
{
    //button->waitForButton();
    //led->ledToggle();
    if(button->checkButton())
    {
        led->ledToggle();
    }
}
