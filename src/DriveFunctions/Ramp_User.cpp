#include "vex.h"
using namespace vex;

void RampUserUp()
{
   //IntakeSpinInAuto(5);
   while(!RampRunning && Controller1.ButtonX.pressing())
   {
   RampMotor.spin(fwd, RampScalar * 100,pct);
   IntakeMotor1.setStopping(brake);
   IntakeMotor2.setStopping(brake);
   }
   //StopIntake();
   RampMotor.stop();
   IntakeMotor1.setStopping(hold);
   IntakeMotor2.setStopping(hold);
}
void RampUserDown()
{
 while(!RampRunning && Controller1.ButtonB.pressing())
 {
 RampMotor.spin(reverse, RampScalar * 100, pct);
 }
 RampMotor.stop();
}
/*
int autoRampRun()
{
 Controller1.ButtonUp.pressed(RampTo90);
Controller1.ButtonDown.pressed(RampToStart);
 while(1)
 {
     this_thread::sleep_for(100);
 }
 return 0;
}
*/
int RampMotorRun()
{
 
RampMotor.resetRotation();
Controller1.ButtonX.pressed(RampUserUp);
Controller1.ButtonB.pressed(RampUserDown);
while(1)
{
 
if (RampMotor.position(degrees) < 0)
{
 RampMotor.resetRotation();
}
this_thread::sleep_for(20);
}
return 0;
}