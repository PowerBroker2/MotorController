#include "MotorController.h"


MotorController motor = MotorController(2, 3, 4);


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
