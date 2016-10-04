
#ifndef STEP_ENGINE_H
#define STEP_ENGINE_H

#include <Arduino.h>

class StepEngine
{
public:
    StepEngine(int engine_pin_1,int engine_pin_2,int engine_pin_3, int engine_pin_4);

    void run();

    // speed setter method:
    void setSpeed(long whatSpeed);

    // mover method:
    void step(int number_of_steps);

private:
    void stepMotor(int thisStep);

    int direction_;                   // Direction of rotation
    unsigned long stepDelay_;         // Delay between steps, in ms, based on speed
    int stepState_;                   // Which step the motor is on
    unsigned long lastStepTimeStamp_; // Time stamp in us of when the last step was taken

    const int enginePin1_;
    const int enginePin2_;
    const int enginePin3_;
    const int enginePin4_;

    const int numberOfSteps_;      // total number of steps this motor can take
};

#endif
