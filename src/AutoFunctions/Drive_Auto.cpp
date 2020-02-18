#include "vex.h"
using namespace vex;
bool SlowDriveRunning = false;
 void DriveForward(double distance, int speed )
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
void DriveBackward(double distance, int speed)
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
void DriveSlowForward()
{
 SlowDriveRunning = true;
 while (Controller1.ButtonUp.pressing())
{
  LeftBack.spin(forward, 10, pct);
  LeftFront.spin(forward, 10, pct);
  RightFront.spin(forward, 10, pct);
  RightBack.spin(forward, 10, pct);

}
LeftBack.stop();
LeftFront.stop();
RightBack.stop();
RightFront.stop();
SlowDriveRunning = false;
}
void DriveSlowBackward()
{
SlowDriveRunning = true;
 while (Controller1.ButtonDown.pressing())
{
  LeftBack.spin(reverse, 10, pct);
  LeftFront.spin(reverse, 10, pct);
  RightFront.spin(reverse, 10, pct);
  RightBack.spin(reverse, 10, pct);

}
LeftBack.stop();
LeftFront.stop();
RightBack.stop();
RightFront.stop();
SlowDriveRunning = false;
}
int SlowDrive()
{
Controller1.ButtonDown.pressed(DriveSlowBackward);
Controller1.ButtonUp.pressed(DriveSlowForward);

while(1)
{
this_thread::sleep_for(100);
}
  return 0;
}
void StrafeRight(double distance, int speed)
{
  DegreesToRotate = (360 * distance) / StrafeDistance;
LeftFront.resetRotation();
LeftBack.resetRotation();
RightFront.resetRotation();
RightBack.resetRotation();
 LeftFront.setVelocity(speed,pct);
LeftBack.setVelocity(speed,pct);
RightFront.setVelocity(speed,pct);
RightBack.setVelocity(speed,pct);
LeftFront.spinFor(DegreesToRotate, degrees, false);
LeftBack.spinFor(-DegreesToRotate, rotationUnits::deg, false);
RightFront.spinFor(-DegreesToRotate, rotationUnits::deg, false);
RightBack.spinFor(DegreesToRotate, rotationUnits::deg, true);
 task::sleep(100);
}
void StrafeLeft(double distance, int speed)
{
DegreesToRotate = (360 * distance) / StrafeDistance;
LeftFront.resetRotation();
LeftBack.resetRotation();
RightFront.resetRotation();
RightBack.resetRotation();
 LeftFront.setVelocity(speed,pct);
LeftBack.setVelocity(speed,pct);
RightFront.setVelocity(speed,pct);
RightBack.setVelocity(speed,pct);
LeftFront.spinFor(-DegreesToRotate, degrees, false);
LeftBack.spinFor(DegreesToRotate, rotationUnits::deg, false);
RightFront.spinFor(DegreesToRotate, rotationUnits::deg, false);
RightBack.spinFor(-DegreesToRotate, rotationUnits::deg, true);
 task::sleep(100);
}