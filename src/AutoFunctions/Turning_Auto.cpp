#include "vex.h"
using namespace vex;

void RightTurn(double angle)
{
  GoalDegrees = Orientation + angle;
  double current = 0;
  double vel = 0;
  while(GyroH.rotation(degrees)<GoalDegrees)
  {
    current = GyroH.rotation(degrees);
error = GoalDegrees - current;
vel = kP * error;
if(vel<8)
{
  vel = 8;
}
LeftFront.spin( directionType::fwd,vel, velocityUnits::pct );
LeftBack.spin(directionType::fwd,vel, velocityUnits::pct);
RightFront.spin( directionType::rev,vel, velocityUnits::pct );
RightBack.spin( directionType::rev,vel, velocityUnits::pct );
task::sleep(20);
}
Orientation += angle;
LeftFront.stop();
LeftBack.stop();
RightFront.stop();
RightBack.stop();
task::sleep(100);
}

void LeftTurn(double angle)
{
  GoalDegrees = Orientation - angle;
  double current = 0;
  double vel = 0;
  while(GyroH.rotation(degrees)>GoalDegrees)
  {
    current = GyroH.rotation(degrees);
error = -(GoalDegrees - current);
vel = kP * error;
if(vel<8)
{
  vel = 8;
}
LeftFront.spin( directionType::rev,vel, velocityUnits::pct );
LeftBack.spin(directionType::rev,vel, velocityUnits::pct);
RightFront.spin( forward,vel, velocityUnits::pct );
RightBack.spin( forward,vel, velocityUnits::pct );
task::sleep(20);
}
Orientation -= angle;
LeftFront.stop();
LeftBack.stop();
RightFront.stop();
RightBack.stop();
task::sleep(100);
  }