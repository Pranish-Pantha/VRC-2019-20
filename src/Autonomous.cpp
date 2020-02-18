#include "vex.h"
using namespace vex;


void autonomous(void) {
  autonomousRan = true;
  setStone = true;
  //side = 3;
  if(side == 0) //BOTTOM RED
  {
    SpinInAuto(90);
    DriveForward(46, 35);
    task::sleep(300);
    DriveBackward(32, 60);
    StopIntake();
    RightTurn(TurnDegrees);
    //StrafeRight(3, 50);
    DriveForward(7, 50);
    RightTurn(32);
    DriveForward(8.75, 40);
    RampTo90();
    DriveForward(1, 40);
    DriveBackward(20, 40);
  }
  if(side==1) //BOTTOM BLUE
  {
    SpinInAuto(90);
    DriveForward(46, 35);
    task::sleep(300);
    DriveBackward(34, 80);
    StopIntake();
    task::sleep(200);
    LeftTurn(TurnDegrees);
    DriveForward(7, 50);
    LeftTurn(33);
    DriveForward(10, 40);
    RampTo90();
    DriveForward(1, 40);
    DriveBackward(20, 40);
  }
  if(side == 2) //TOP RED
  {
    SpinInAuto(90);
    DriveForward(46, 35);
    task::sleep(300);
    DriveBackward(38, 70);
    StopIntake();
    LeftTurn(TurnDegrees+2.5);
    StrafeLeft(5, 50);
    DriveForward(27, 50);
    RampTo90();
    DriveBackward(20, 40);
  }
  if(side == 3) //TOP BLUE
  {
    SpinInAuto(90);
    DriveForward(44, 35);
    task::sleep(300);
    DriveBackward(36, 70);
    StopIntake();
    RightTurn(TurnDegrees);
    StrafeRight(5, 50);
    DriveForward(28.25, 40);
    RampTo90();
    DriveBackward(20, 40);
  }
  if(side == 4) //None
  {
  }
  if(side==5)//8 cubes?
  {
      SpinInAuto(90);
      DriveForward(43, 35);
    task::sleep(300);
    DriveBackward(41.5, 50);
    StopIntake();
    StrafeRight(24.25, 35);
    SpinInAuto(90);
     DriveForward(44.5, 35);
    task::sleep(300);
    DriveBackward(30.5, 30);
    StopIntake();
    task::sleep(2000);
    kP = 1.1;
    RightTurn(TurnDegrees);
    //StrafeRight(3, 50);
    DriveForward(5, 50);
    kP = 0.9;
    RightTurn(40);
    DriveForward(8.75, 40);
    RampTo90();
    DriveForward(0.7, 40);
    DriveBackward(20, 40);
  }
}
