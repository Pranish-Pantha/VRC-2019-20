#include "vex.h"
using namespace vex;

void SpinIn()
{
while (Controller1.ButtonL1.pressing())
{
  IntakeMotor1.spin(forward, 100*IntakeScalar, pct);
  IntakeMotor2.spin(forward, 100*IntakeScalar, pct);
}
IntakeMotor1.stop();
IntakeMotor2.stop();
}
void SpinOut()
{

while (Controller1.ButtonL2.pressing())
{
  IntakeMotor1.spin(reverse, 100*IntakeScalar, pct);
  IntakeMotor2.spin(reverse, 100*IntakeScalar, pct);
}
IntakeMotor1.stop();
IntakeMotor2.stop();
}
void SlowSpinIn()
{
while (Controller1.ButtonY.pressing())
{
  IntakeMotor1.spin(forward, 8, pct);
  IntakeMotor2.spin(forward, 8, pct);
}
IntakeMotor1.stop();
IntakeMotor2.stop();
}
void SlowSpinOut()
{
while (Controller1.ButtonA.pressing())
{
  IntakeMotor1.spin(reverse, 8, pct);
  IntakeMotor2.spin(reverse, 8, pct);
}
IntakeMotor1.stop();
IntakeMotor2.stop();
}
int IntakeRun()
{
Controller1.ButtonL1.pressed(SpinIn);
Controller1.ButtonL2.pressed(SpinOut);
Controller1.ButtonA.pressed(SlowSpinOut);
Controller1.ButtonY.pressed(SlowSpinIn);
while(1)
{
this_thread::sleep_for(100);
}
return 0;
}
