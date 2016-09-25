
#include "utility.h"
#include "globals.h"


void LED::blink()
{
    const int blinkDuration = 1 * 1000; // ms

    delay(blinkDuration);   // wait for a second
	sendLedState(ledOn);    // set the LED on
	delay(blinkDuration);   // wait for a second
	sendLedState(ledOff);   // set the LED off
}

void LED::ledToggle()
{
    if(ledState_ == ledOn)
    {
        sendLedState(ledOff);
        ledState_ = ledOff;
    }
    else if(ledState_ == ledOff)
    {
        sendLedState(ledOn);
        ledState_ = ledOn;
    }
    else
    {
        Serial.println("Illeagal LED instruction: " + ledState_);
    }
}
void LED::sendLedState(uint8_t instruction)
{
    digitalWrite(ledPin_, instruction);
}

bool Button::checkButton()
{
    uint8_t currentButtonState = getButtonState();
    if(currentButtonState != oldButtonState_)
    {
		oldButtonState_ = currentButtonState;
		return true;
    }
	else
	{
		oldButtonState_ = currentButtonState;
		return false;
	}
}

void Button::waitForButton()
{
    uint8_t buttonState = getButtonState();
	Serial.println("Wait for button down...");
    while (buttonState != buttonDown)
    {
        buttonState = getButtonState();
        delay(delayTime_);
    }
    buttonState = getButtonState();
	Serial.println("Wait for button up...");
    while (buttonState != buttonUp)
    {
        buttonState = getButtonState();
        delay(delayTime_);
    }
}

uint8_t Button::getButtonState()
{
    uint8_t state = digitalRead(buttonPin_);
    return state;
}

