#include "MotorController.h"




MotorController::MotorController(const byte& _pwmPin, const byte& _in1, const byte& _in2)
{
	pwmPin = _pwmPin;
	in1    = _in1;
	in2    = _in2;

	pinMode(pwmPin, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
}




void MotorController::write(const int& _speed)
{
	if (_speed > 0)
		forward(_speed);
	else
		reverse(_speed);
}




void MotorController::forward(const int& _speed)
{
	speed = abs(_speed);
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	analogWrite(pwmPin, speed);
}




void MotorController::brake()
{
	speed = 0;
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	analogWrite(pwmPin, speed);
}




void MotorController::free()
{
	speed = 0;
	digitalWrite(in1, HIGH);
	digitalWrite(in2, HIGH);
	analogWrite(pwmPin, speed);
}




void MotorController::reverse(const int& _speed)
{
	speed = abs(_speed);
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	analogWrite(pwmPin, speed);
}




int MotorController::read()
{
	return speed;
}