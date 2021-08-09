#include "MotorController.h"


StepperMotorController motor = StepperMotorController(200, 2, 3, 4, 5); // numTotalSteps, in1Pin, in2Pin, in3Pin, in4Pin


void setup()
{
  motor.setSpeed(100); // rpm
}


void loop()
{
  motor.step(200); // rotate through 200 steps in one direction
  delay(5000);
  motor.step(-200); // rotate through 200 steps in the other direction
}
