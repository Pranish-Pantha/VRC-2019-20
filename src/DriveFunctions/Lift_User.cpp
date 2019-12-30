#include "vex.h"
using namespace vex;

void LiftUp()
{
 RampMotor.setStopping(coast);
while (Controller1.ButtonR1.pressing())
{
  LiftMotor.spin(forward, 100*LiftScalar, pct);
}
LiftMotor.stop();
RampMotor.setStopping(hold);
}
void LiftDown()
{
 RampMotor.setStopping(coast);
while (Controller1.ButtonR2.pressing())
{
  LiftMotor.spin(reverse, 100*LiftScalar, pct);
}
LiftMotor.stop();
RampMotor.setStopping(hold);
}
int LiftRun()
{
Controller1.ButtonR1.pressed(LiftUp);
Controller1.ButtonR2.pressed(LiftDown);
while(1)
{
this_thread::sleep_for(100);
}
return 0;
}