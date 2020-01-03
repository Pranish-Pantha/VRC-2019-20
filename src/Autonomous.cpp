#include "vex.h"
using namespace vex;


void autonomous(void) {
  int side = 1;

  if(side == 0) //BOTTOM RED
  {
    SpinInAuto(80);
    DriveForward(40, 35);
    DriveBackward(35, 50);
    StopIntake();
    RightTurn(TurnDegrees);
    DriveForward(15, 35);
    RampTo90();
    DriveBackward(20, 25);
  }
  if(side==1) //BOTTOM BLUE
  {
    SpinInAuto(80);
    DriveForward(40, 70);
    DriveBackward(35, 70);
    StopIntake();
    LeftTurn(TurnDegrees);
    DriveForward(15, 50);
    RampTo90();
    DriveBackward(20, 25);
  }
  if(side == 2) //TOP RED
  {
    SpinInAuto(80);
    DriveForward(40, 70);
    DriveBackward(35, 70);
    StopIntake();
    LeftTurn(TurnDegrees);
    DriveForward(25, 50);
    RampTo90();
    DriveBackward(20, 25);
  }
  if(side == 3) //TOP BLUE
  {
    SpinInAuto(80);
    DriveForward(40, 70);
    DriveBackward(35, 70);
    StopIntake();
    RightTurn(TurnDegrees);
    DriveForward(25, 50);
    RampTo90();
    DriveBackward(20, 25);
  }
  if(side == 4) //TESTING
  {
    LeftFront.setVelocity(10, pct);
    LeftBack.setVelocity(10, pct);
    RightFront.setVelocity(10, pct);
    RightBack.setVelocity(10, pct);
    LeftFront.spinFor(fwd, 1, rev, false);
    LeftBack.spinFor(reverse, 1, rev, false);
    RightFront.spinFor(reverse, 1, rev, false);
    RightBack.spinFor(fwd, 1, rev, true);
  }
}
