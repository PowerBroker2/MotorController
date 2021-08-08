#include "MotorController.h"


BLDCMotorController motor = BLDCMotorController(2, 3, 4); // pwmPin, dirPin, sigPin


void setup()
{
  
}


void loop()
{
  motor.write(255);
  delay(5000);
  
  motor.write(0);
  delay(5000);
  
  motor.write(-255);
  delay(5000);
}
