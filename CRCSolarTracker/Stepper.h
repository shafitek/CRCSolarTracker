// Stepper.h

#ifndef _STEPPER_h
#define _STEPPER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
class Stepper {
public:
	// constructors:
	Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2,
								 int motor_pin_3, int motor_pin_4);
	// speed setter method:
	void setSpeed(long whatSpeed);
	// mover method:
	void step(int number_of_steps);

private:
	void stepMotor(int this_step);

	int direction;            // Direction of rotation
	unsigned long step_delay; // delay between steps, in ms, based on speed
	int number_of_steps;      // total number of steps this motor can take
	int pin_count;            // how many pins are in use.
	int step_number;          // which step the motor is on

	// motor pin numbers:
	int motor_pin_1;
	int motor_pin_2;
	int motor_pin_3;
	int motor_pin_4;

	unsigned long last_step_time; // time stamp in us of when the last step was taken
};

#endif

