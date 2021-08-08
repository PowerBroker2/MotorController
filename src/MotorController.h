#pragma once
#include "Arduino.h"




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