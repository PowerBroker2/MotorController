#pragma once
#include "Arduino.h"




class MotorController
{
public:
	MotorController(const byte& _pwmPin, const byte& _in1, const byte& _in2);
	void write(const int& _speed);
	void forward(const int& _speed);
	void brake();
	void free();
	void reverse(const int& _speed);
	int read();

private:
	int speed;
	byte pwmPin;
	byte in1;
	byte in2;
};