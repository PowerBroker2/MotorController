#include "MotorController.h"




DCMotorController::DCMotorController(const byte& _pwmPin, const byte& _in1Pin, const byte& _in2Pin)
{
	pwmPin = _pwmPin;
	in1Pin    = _in1Pin;
	in2Pin    = _in2Pin;

	pinMode(pwmPin, OUTPUT);
	pinMode(in1Pin, OUTPUT);
	pinMode(in2Pin, OUTPUT);
}




void DCMotorController::write(const int& _speed)
{
	if (_speed > 0)
		forward(_speed);
	else
		reverse(_speed);
}




void DCMotorController::forward(const int& _speed)
{
	speed = abs(_speed);
	digitalWrite(in1Pin, HIGH);
	digitalWrite(in2Pin, LOW);
	analogWrite(pwmPin, speed);
}




void DCMotorController::brake()
{
	speed = 0;
	digitalWrite(in1Pin, LOW);
	digitalWrite(in2Pin, LOW);
	analogWrite(pwmPin, speed);
}




void DCMotorController::free()
{
	speed = 0;
	digitalWrite(in1Pin, HIGH);
	digitalWrite(in2Pin, HIGH);
	analogWrite(pwmPin, speed);
}




void DCMotorController::reverse(const int& _speed)
{
	speed = abs(_speed);
	digitalWrite(in1Pin, LOW);
	digitalWrite(in2Pin, HIGH);
	analogWrite(pwmPin, speed);
}




int DCMotorController::read()
{
	return speed;
}




BLDCMotorController::BLDCMotorController(const byte& _pwmPin, const byte& _dirPin, const byte& _sigPin)
{
	pwmPin = _pwmPin;
	dirPin = _dirPin;
	sigPin = _sigPin;

	pinMode(pwmPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
}




void BLDCMotorController::write(const int& _speed)
{
	if (_speed > 0)
		forward(_speed);
	else
		reverse(_speed);
}




void BLDCMotorController::forward(const int& _speed)
{
	speed = abs(_speed);
	digitalWrite(dirPin, HIGH);
	analogWrite(pwmPin, speed);
}




void BLDCMotorController::reverse(const int& _speed)
{
	speed = abs(_speed);
	digitalWrite(dirPin, LOW);
	analogWrite(pwmPin, speed);
}




int BLDCMotorController::read()
{
	return speed;
}