#include "vex.h"
using namespace vex;
void RampTo90()
{
 if(!Controller1.ButtonX.pressing() && !Controller1.ButtonB.pressing() && !To0Running)
{
  RampRunning = true;
  To90Running = true;
  IntakeMotor1.setStopping(brake);
  IntakeMotor2.setStopping(brake);
  SpinOutAuto(30);
    task::sleep(1200);
  StopIntake();
  RampMotor.setVelocity(35, pct);
  /*
  double num = 700;
  RampMotor.spinFor(0.586*num, degrees, true);
  StopIntake();
  task::sleep(500);
  RampMotor.spinFor(0.414*num, degrees, true);
    */
  RampMotor.spinFor(350, degrees, true);
  SpinOutAuto(20);
  RampMotor.spinFor(350, degrees, true);
  //RampMotor.spinToPosition(700, degrees, true);
}
RampMotor.stop();
StopIntake();
IntakeMotor1.setStopping(hold);
  IntakeMotor2.setStopping(hold);
RampRunning = false;
To90Running = false;
}
void RampToStart()
{
 if(!Controller1.ButtonX.pressing() && !Controller1.ButtonB.pressing() && !To90Running)
{
  RampRunning = true;
  To0Running = true;
  RampMotor.setVelocity(45, pct);
  SpinInAuto(10);
RampMotor.spinFor(-700, degrees, true);
}
StopIntake();
RampRunning = false;
To0Running = false;
}
