#include "MotorController.h"




DCMotorController::DCMotorController(const byte& _pwmPin, const byte& _in1Pin, const byte& _in2Pin)
{
	pwmPin = _pwmPin;
	in1Pin = _in1Pin;
	in2Pin = _in2Pin;

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




StepperMotorController::StepperMotorController(const int& _numTotalSteps, const byte& _in1Pin, const byte& _in2Pin)
{
    stepNum = 0;
    numTotalSteps = _numTotalSteps;

    in1Pin = _in1Pin;
    in2Pin = _in2Pin;

    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);

    type = 2;

    setSpeed(1);
}




StepperMotorController::StepperMotorController(const int& _numTotalSteps, const byte& _in1Pin, const byte& _in2Pin, const byte& _in3Pin, const byte& _in4Pin)
{
    stepNum = 0;
    numTotalSteps = _numTotalSteps;

    in1Pin = _in1Pin;
    in2Pin = _in2Pin;
    in3Pin = _in3Pin;
    in4Pin = _in4Pin;

    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);
    pinMode(in3Pin, OUTPUT);
    pinMode(in4Pin, OUTPUT);

    type = 4;

    setSpeed(1);
}




StepperMotorController::StepperMotorController(const int& _numTotalSteps, const byte& _in1Pin, const byte& _in2Pin, const byte& _in3Pin, const byte& _in4Pin, const byte& _in5Pin)
{
    stepNum = 0;
    numTotalSteps = _numTotalSteps;

    in1Pin = _in1Pin;
    in2Pin = _in2Pin;
    in3Pin = _in3Pin;
    in4Pin = _in4Pin;
    in5Pin = _in5Pin;

    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);
    pinMode(in3Pin, OUTPUT);
    pinMode(in4Pin, OUTPUT);
    pinMode(in5Pin, OUTPUT);

    type = 5;

    setSpeed(1);
}




void StepperMotorController::setSpeed(const long& rpm)
{
	delayMicroseconds = 60000000 / (rpm * numTotalSteps);
	timer.begin(delayMicroseconds, MICRO_SECONDS);
}




void StepperMotorController::step(const int& numSteps)
{
	int steps_left = abs(numSteps);
	dir = steps_left > 0;

	timer.start();

	while (steps_left)
	{
		if (timer.fire())
		{
			if (dir)
			{
				stepNum++;

				if (stepNum == numTotalSteps)
					stepNum = 0;
			}
			else
			{
				if (!stepNum)
					stepNum = numTotalSteps;

				stepNum--;
			}

			steps_left--;

			if (type == 5)
				stepMotor(stepNum % 10);
			else
				stepMotor(stepNum % 4);
		}
	}
}




void StepperMotorController::stepMotor(const int& curStep)
{
    switch (type)
    {
        case 2:
        {
            switch (curStep)
            {
                case 0:
                {
                    digitalWrite(in1Pin, LOW);
                    digitalWrite(in2Pin, HIGH);
                    break;
                }

                case 1:
                {
                    digitalWrite(in1Pin, HIGH);
                    digitalWrite(in2Pin, HIGH);
                    break;
                }
                    
                case 2:
                {
                    digitalWrite(in1Pin, HIGH);
                    digitalWrite(in2Pin, LOW);
                    break;
                }

                case 3:
                {
                    digitalWrite(in1Pin, LOW);
                    digitalWrite(in2Pin, LOW);
                    break;
                }
            }

            break;
        }

        case 4:
        {
            switch (curStep)
            {
                case 0:
                {
                    digitalWrite(in1Pin, HIGH);
                    digitalWrite(in2Pin, LOW);
                    digitalWrite(in3Pin, HIGH);
                    digitalWrite(in4Pin, LOW);
                    break;
                }

                case 1:
                {
                    digitalWrite(in1Pin, LOW);
                    digitalWrite(in2Pin, HIGH);
                    digitalWrite(in3Pin, HIGH);
                    digitalWrite(in4Pin, LOW);
                    break;
                }

                case 2:
                {
                    digitalWrite(in1Pin, LOW);
                    digitalWrite(in2Pin, HIGH);
                    digitalWrite(in3Pin, LOW);
                    digitalWrite(in4Pin, HIGH);
                    break;
                }

                case 3:
                {
                    digitalWrite(in1Pin, HIGH);
                    digitalWrite(in2Pin, LOW);
                    digitalWrite(in3Pin, LOW);
                    digitalWrite(in4Pin, HIGH);
                    break;
                }
            }

            break;
        }

        case 5:
        {
            switch (curStep)
            {
                case 0:
                {
                    digitalWrite(in1Pin, LOW);
                    digitalWrite(in2Pin, HIGH);
                    digitalWrite(in3Pin, HIGH);
                    digitalWrite(in4Pin, LOW);
                    digitalWrite(in5Pin, HIGH);
                    break;
                }

                case 1:
                {
                    digitalWrite(in1Pin, LOW);
                    digitalWrite(in2Pin, HIGH);
                    digitalWrite(in3Pin, LOW);
                    digitalWrite(in4Pin, LOW);
                    digitalWrite(in5Pin, HIGH);
                    break;
                }

                case 2:
                {
                    digitalWrite(in1Pin, LOW);
                    digitalWrite(in2Pin, HIGH);
                    digitalWrite(in3Pin, LOW);
                    digitalWrite(in4Pin, HIGH);
                    digitalWrite(in5Pin, HIGH);
                    break;
                }

                case 3:
                {
                    digitalWrite(in1Pin, LOW);
                    digitalWrite(in2Pin, HIGH);
                    digitalWrite(in3Pin, LOW);
                    digitalWrite(in4Pin, HIGH);
                    digitalWrite(in5Pin, LOW);
                    break;
                }

                case 4:
                {
                    digitalWrite(in1Pin, HIGH);
                    digitalWrite(in2Pin, HIGH);
                    digitalWrite(in3Pin, LOW);
                    digitalWrite(in4Pin, HIGH);
                    digitalWrite(in5Pin, LOW);
                    break;
                }

                case 5:
                {
                    digitalWrite(in1Pin, HIGH);
                    digitalWrite(in2Pin, LOW);
                    digitalWrite(in3Pin, LOW);
                    digitalWrite(in4Pin, HIGH);
                    digitalWrite(in5Pin, LOW);
                    break;
                }

                case 6:
                {
                    digitalWrite(in1Pin, HIGH);
                    digitalWrite(in2Pin, LOW);
                    digitalWrite(in3Pin, HIGH);
                    digitalWrite(in4Pin, HIGH);
                    digitalWrite(in5Pin, LOW);
                    break;
                }

                case 7:
                {
                    digitalWrite(in1Pin, HIGH);
                    digitalWrite(in2Pin, LOW);
                    digitalWrite(in3Pin, HIGH);
                    digitalWrite(in4Pin, LOW);
                    digitalWrite(in5Pin, LOW);
                    break;
                }

                case 8:
                {
                    digitalWrite(in1Pin, HIGH);
                    digitalWrite(in2Pin, LOW);
                    digitalWrite(in3Pin, HIGH);
                    digitalWrite(in4Pin, LOW);
                    digitalWrite(in5Pin, HIGH);
                    break;
                }

                case 9:
                {
                    digitalWrite(in1Pin, LOW);
                    digitalWrite(in2Pin, LOW);
                    digitalWrite(in3Pin, HIGH);
                    digitalWrite(in4Pin, LOW);
                    digitalWrite(in5Pin, HIGH);
                    break;
                }
            }

            break;
        }
    }
}