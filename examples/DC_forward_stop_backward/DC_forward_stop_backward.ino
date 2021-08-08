#include "MotorController.h"


DCMotorController motor = DCMotorController(2, 3, 4); // pwmPin, in1, in2


void setup()
{
  
}


void loop()
{
  motor.write(255);
  delay(5000);
  
  motor.brake();
  delay(5000);
  
  motor.write(-255);
  delay(5000);
}
