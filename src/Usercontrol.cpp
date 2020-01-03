#include "vex.h"
using namespace vex;

double LF, LB, RF, RB;
double y, x1, x2, y2;
double threshold = 10.0;
bool yactive, x1active, x2active, y2active, turning, strafing;
void usercontrol(void) {
  
  thread Rampthread = thread(RampMotorRun);

thread autoRampthread = thread(AutoRampRun);
//thread PrintToController = thread(toController);

thread Intakethread = thread(IntakeRun);
thread Liftthread = thread(LiftRun);
Controller1.ButtonRight.pressed(IncreaseSensitivity);
Controller1.ButtonLeft.pressed(DecreaseSensitivity);

while (1) {
LF = 0;
LB = 0;
RF = 0;
RB = 0;
y  =  DriveScalar*Controller1.Axis3.position();
x1 = DriveScalar*Controller1.Axis4.position();
x2 = DriveScalar*Controller1.Axis1.position();
y2 = DriveScalar*Controller1.Axis2.position();
threshold = 10.0;
yactive = false;
   x1active = false;
   x2active = false;
   y2active = false;
   turning = false;
if( fabs(y) > threshold)
       {
         LF += y;
         LB += y;
         RF += y;
         RB += y;
         yactive = true;
       }
     if(fabs(x1)>threshold)
     {
         LF += x1;
         LB += x1;
         RF -= x1;
         RB -= x1;
         x1active = true;
         turning = true;
     }
     if ( fabs(y2) > threshold)
     {
         LF += y2;
         LB += y2;
         RF += y2;
         RB += y2;
         y2active = true;
     }
     if ( fabs(x2) > threshold)
     {
         LF += x2;
         LB -= x2;
         RF -= x2;
         RB += x2;
         x2active = true;
         strafing = true;
        
     }
     else{
       strafing = false;
       //GyroH.setHeading(0, deg);
         error = 0;
   derivative = 0;
   previousError = 0;
     }
   if((yactive&&(x2active||y2active))||(x1active&&(y2active||x2active)))
     {
       LF = LF * DriveScalar;
       LB = LB * DriveScalar;
       RF = RF * DriveScalar;
       RB = RB * DriveScalar;
     }
   if(strafing && !turning)
   {
     /*
       error = GyroH.heading();
       derivative =  error- previousError;
       previousError = error;
     LF += kPStrafe*error + kDStrafe * derivative;
     LB -= kPStrafe*error + kDStrafe * derivative;
     RF -= kPStrafe*error + kDStrafe * derivative;
     RB += kPStrafe*error + kDStrafe * derivative;
     */
   }
   LeftFront.spin(fwd, LF, pct);
     LeftBack.spin(fwd, LB, pct);
     RightFront.spin(fwd, RF, pct);
     RightBack.spin(fwd, RB, pct);
task::sleep(20);
}
}
