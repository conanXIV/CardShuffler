
#ifndef UTILITY_H
#define UTILITY_H

#include <Arduino.h>

class LED
{
public:
    LED(int ledPin)
    : ledPin_(ledPin), delayTime_(10), ledOn(HIGH), ledOff(LOW), ledState_(LOW) {};

    void blink();
    void ledToggle();

private:
    const uint8_t ledOn;
    const uint8_t ledOff;
    const int ledPin_;
    const int delayTime_; // ms

    uint8_t ledState_;

    void sendLedState(uint8_t instruction);
};

class Button
{
public:
    Button(int buttonPin)
    : buttonPin_(buttonPin), delayTime_(10), buttonDown(HIGH), buttonUp(LOW), oldButtonState_(LOW) {};

	bool checkButton();
    void waitForButton();

private:
    const uint8_t buttonDown;
    const uint8_t buttonUp;
    const int buttonPin_;
    const int delayTime_; // ms

	uint8_t oldButtonState_;
	
    uint8_t getButtonState();
};



#endif
