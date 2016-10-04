
#include "step-engine.h"
#include "globals.h"

//---( Steps per OUTPUT SHAFT of gear reduction )---
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048 

StepEngine::StepEngine(int enginePin1,int enginePin2,int enginePin3, int enginePin4)
  : enginePin1_(enginePin1), enginePin2_(enginePin2), enginePin3_(enginePin3), enginePin4_(enginePin4), numberOfSteps_(32)
{ 
    stepState_ = 0;      // which step the motor is on
    direction_ = 0;        // motor direction
    lastStepTimeStamp_ = 0;   // time stamp in us of the last step taken
}

void StepEngine::run()
{ 
	int Steps2Take;
    Steps2Take = 3 * STEPS_PER_OUTPUT_REVOLUTION / 2;  // Rotate CW 3/2 turn
    setSpeed(1000);   
    step(Steps2Take);
    delay(1000);
  
    Steps2Take =  - STEPS_PER_OUTPUT_REVOLUTION / 2;  // Rotate CCW 1/2 turn  
    setSpeed(700); 
    step(Steps2Take);
    delay(1000);
}

void StepEngine::setSpeed(long speed)
{
    stepDelay_ = 60L * 1000L * 1000L / numberOfSteps_ / speed;
}

/*
 * Moves the motor stepsToMove steps.  If the number is negative,
 * the motor moves in the reverse direction.
 */
void StepEngine::step(int stepsToMove)
{
	int stepsLeft = abs(stepsToMove);  // how many steps to take

	// determine direction based on whether steps_to_mode is + or -:
	
	if (stepsToMove > 0) 
		direction_ = 1;
	else if (stepsToMove < 0) 
		direction_ = -1;

	// decrement the number of steps, moving one step each time:
	while (stepsLeft > 0)
	{
		unsigned long now = micros();
		// move only if the appropriate delay has passed:
		if (now - lastStepTimeStamp_ >= stepDelay_)
		{
			// get the timeStamp of when you stepped:
			lastStepTimeStamp_ = now;
			// increment or decrement the step number,
			// depending on direction:
			if (direction_ == 1)
			{	
				stepState_++;
				if (stepState_ == numberOfSteps_) 
					stepState_ = 0;
			}
			else
			{
				if (stepState_ == 0)
					stepState_ = numberOfSteps_;
				stepState_--;
			}
			// decrement the steps left:
			stepsLeft--;
			// step the motor to step number 0, 1, 2, 3
			stepMotor(stepState_ % 4);
		}
	}
}

void StepEngine::stepMotor(int state)
{
	if(state == 0) // 1010
	{
		digitalWrite(enginePin1_, HIGH);
		digitalWrite(enginePin2_, LOW);
		digitalWrite(enginePin3_, HIGH);
		digitalWrite(enginePin4_, LOW);
	}
	else if(state == 1) // 0110
	{
		digitalWrite(enginePin1_, LOW);
		digitalWrite(enginePin2_, HIGH);
		digitalWrite(enginePin3_, HIGH);
		digitalWrite(enginePin4_, LOW);
	}
	else if(state == 2) //0101
	{
		digitalWrite(enginePin1_, LOW);
		digitalWrite(enginePin2_, HIGH);
		digitalWrite(enginePin3_, LOW);
		digitalWrite(enginePin4_, HIGH);
	}
	else if(state == 3) //1001
	{
		digitalWrite(enginePin1_, HIGH);
		digitalWrite(enginePin2_, LOW);
		digitalWrite(enginePin3_, LOW);
		digitalWrite(enginePin4_, HIGH);
	}
    else // Error unknown state
	{
		Serial.println("Error unknown state: " + state);
	}
}


