#include "vex.h"
using namespace vex;
void RampTo90()
{
 if(!Controller1.ButtonX.pressing() && !Controller1.ButtonB.pressing() && !To0Running)
{
  RampRunning = true;
  To90Running = true;
  
  RampMotor.spin(fwd, 35, pct);
  task::sleep(1700);
}
RampMotor.stop();
RampRunning = false;
To90Running = false;
}
void RampToStart()
{
 if(!Controller1.ButtonX.pressing() && !Controller1.ButtonB.pressing() && !To90Running)
{
  RampRunning = true;
  To0Running = true;
  RampMotor.setVelocity(33, pct);
RampMotor.spinFor(-210, degrees, true);
}
RampRunning = false;
To0Running = false;
}
int AutoRampRun()
{
  Controller1.ButtonUp.pressed(RampTo90);
Controller1.ButtonDown.pressed(RampToStart);
 while(1)
 {
     this_thread::sleep_for(100);
 }
  return 0;
}