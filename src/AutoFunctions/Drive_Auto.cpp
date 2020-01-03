#include "vex.h"
using namespace vex;
 void DriveForward(int distance, int speed )
{
// finding how many degrees rotations are needed
DegreesToRotate = (360 * distance) / Circumference;
LeftFront.resetRotation();
LeftBack.resetRotation();
RightFront.resetRotation();
RightBack.resetRotation();
 
LeftFront.setVelocity(speed,pct);
LeftBack.setVelocity(speed,pct);
RightFront.setVelocity(speed,pct);
RightBack.setVelocity(speed,pct);
LeftFront.spinFor(DegreesToRotate, degrees, false);
LeftBack.spinFor(DegreesToRotate, rotationUnits::deg, false);
RightFront.spinFor(DegreesToRotate, rotationUnits::deg, false);
RightBack.spinFor(DegreesToRotate, rotationUnits::deg, true);
 task::sleep(100);
}
void DriveBackward(int distance, int speed)
{
// finding how many degrees rotations are needed
DegreesToRotate = (360 * distance) / Circumference;
LeftFront.resetRotation();
LeftBack.resetRotation();
RightFront.resetRotation();
RightBack.resetRotation();
LeftFront.setVelocity(speed,pct);
LeftBack.setVelocity(speed,pct);
RightFront.setVelocity(speed,pct);
RightBack.setVelocity(speed,pct);
LeftFront.spinFor(-DegreesToRotate, degrees, false);
LeftBack.spinFor(-DegreesToRotate, rotationUnits::deg, false);
RightFront.spinFor(-DegreesToRotate, rotationUnits::deg, false);
RightBack.spinFor(-DegreesToRotate, rotationUnits::deg, true);
 
task::sleep(100);
}