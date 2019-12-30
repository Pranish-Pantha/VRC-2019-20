/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftFront            motor         7               
// LeftBack             motor         10              
// RightFront           motor         2               
// RightBack            motor         1               
// RampMotor            motor         4               
// LiftMotor            motor         3               
// IntakeMotor1         motor         6               
// IntakeMotor2         motor         15              
// GyroH                gyro          H               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;
// A global instance of competition
competition Competition;
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  preAuto();
  while (true) {
    wait(100, msec);
  }
}
