#include "vex.h"
using namespace vex;

void IncreaseSensitivity()
{
  DriveScalar +=0.05;
  RampScalar +=0.05;
  LiftScalar +=0.05;
  IntakeScalar += 0.05;
}
void DecreaseSensitivity()
{
  DriveScalar -=0.05;
  RampScalar -=0.05;
  LiftScalar -=0.05;
  IntakeScalar -=0.05;
}
