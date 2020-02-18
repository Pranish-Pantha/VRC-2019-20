#include "vex.h"
using namespace vex;

void LiftUp()
{
 
while (Controller1.ButtonR1.pressing())
{
  
  if(RampMotor.position(degrees)<100 && !RampRunning)
  {
    RampMotor.spinTo(280,  degrees, true);
  }
  
  LiftMotor.spin(forward, 100*LiftScalar, pct);
}
LiftMotor.stop();
}
void LiftDown()
{
while (Controller1.ButtonR2.pressing())
{
  
  LiftMotor.spin(reverse, 100*LiftScalar, pct);
}
LiftMotor.stop();
}
