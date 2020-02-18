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
void SpinInSoumil()
{
  while (Controller1.ButtonL2.pressing())
{
  IntakeMotor1.spin(forward, 100*IntakeScalar, pct);
  IntakeMotor2.spin(forward, 100*IntakeScalar, pct);
}
IntakeMotor1.stop();
IntakeMotor2.stop();
}
void SpinOutSoumil()
{
  while (Controller1.ButtonL1.pressing())
{
  IntakeMotor1.spin(reverse, 100*IntakeScalar, pct);
  IntakeMotor2.spin(reverse, 100*IntakeScalar, pct);
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
  IntakeMotor1.spin(forward, 20, pct);
  IntakeMotor2.spin(forward, 20, pct);
}
IntakeMotor1.stop();
IntakeMotor2.stop();
}
void SlowSpinOut()
{
while (Controller1.ButtonA.pressing())
{
  IntakeMotor1.spin(reverse, 20, pct);
  IntakeMotor2.spin(reverse, 20, pct);
}
IntakeMotor1.stop();
IntakeMotor2.stop();
}

