#include "vex.h"
using namespace vex;


void preAuto(void) {
vexcodeInit();
GyroH.calibrate();
waitUntil(!GyroH.isCalibrating());
GyroH.setHeading(0, degrees);
LeftFront.setStopping(hold);
LeftBack.setStopping(hold);
RightFront.setStopping(hold);
RightBack.setStopping(hold);
RampMotor.setStopping(hold);
LiftMotor.setStopping(hold);
IntakeMotor1.setStopping(hold);
IntakeMotor2.setStopping(hold);
}