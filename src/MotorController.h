#pragma once
#include "Arduino.h"
#include "FireTimer.h"




class DCMotorController
{
public:
	DCMotorController(const byte& _pwmPin, const byte& _in1Pin, const byte& _in2Pin);
	void write(const int& _speed);
	void forward(const int& _speed);
	void brake();
	void free();
	void reverse(const int& _speed);
	int read();

private:
	int speed;
	byte pwmPin;
	byte in1Pin;
	byte in2Pin;
};




class BLDCMotorController
{
public:
	BLDCMotorController(const byte& _pwmPin, const byte& _dirPin, const byte& _sigPin);
	void write(const int& _speed);
	void forward(const int& _speed);
	void reverse(const int& _speed);
	int read();

private:
	int speed;
	int signal;
	byte pwmPin;
	byte dirPin;
	byte sigPin;
};




class StepperMotorController
{
public:
	StepperMotorController(const int& _numTotalSteps, const byte& _in1Pin, const byte& _in2Pin);
	StepperMotorController(const int& _numTotalSteps, const byte& _in1Pin, const byte& _in2Pin, const byte& _in3Pin, const byte& _in4Pin);
	StepperMotorController(const int& _numTotalSteps, const byte& _in1Pin, const byte& _in2Pin, const byte& _in3Pin, const byte& _in4Pin, const byte& _in5Pin);

	void setSpeed(const long& rpm);
	void step(const int& numSteps);
	void stepMotor(const int& curStep);

private:
	FireTimer timer;

	byte type;
	int numTotalSteps;
	int stepNum;
	bool dir;
	long delayMicroseconds;
	byte in1Pin;
	byte in2Pin;
	byte in3Pin;
	byte in4Pin;
	byte in5Pin;
};