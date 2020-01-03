#include "vex.h"
using namespace vex;

int SpinInAuto(int speed)
{
IntakeMotor1.spin(forward, speed, pct);
IntakeMotor2.spin(forward, speed, pct);
return 0;
}
//Spins intake out
int SpinOutAuto(int speed)
{
IntakeMotor1.spin(reverse, speed, pct);
IntakeMotor2.spin(reverse, speed, pct);
return 0;
}
//Stops intake
void StopIntake()
{
IntakeMotor1.stop();
IntakeMotor2.stop();
}