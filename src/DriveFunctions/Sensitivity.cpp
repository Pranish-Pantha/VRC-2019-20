#include "vex.h"
using namespace vex;

void IncreaseSensitivity()
{
  DriveScalar +=0.1;
  RampScalar +=0.1;
  LiftScalar +=0.1;
  IntakeScalar += 0.1;
}
void DecreaseSensitivity()
{
  DriveScalar -=0.1;
  RampScalar -=0.1;
  LiftScalar -=0.1;
  IntakeScalar -= 0.1;
}
