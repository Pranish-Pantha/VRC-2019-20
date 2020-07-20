#include "main.h"
void SpinIn()
{
while (master.get_digital(DIGITAL_L1))
{
  Intake1.move_velocity(100*IntakeScalar);
  Intake2.move_velocity(100*IntakeScalar);
}
Intake1.move_velocity(0);
Intake2.move_velocity(0);
}
void SpinOut()
{
while (master.get_digital(DIGITAL_L2))
{
  Intake1.move_velocity(-100*IntakeScalar);
  Intake2.move_velocity(-100*IntakeScalar);
}
Intake1.move_velocity(0);
Intake2.move_velocity(0);
}
void SlowSpinIn()
{
while (master.get_digital(DIGITAL_Y))
{
  Intake1.move_velocity(8);
  Intake2.move_velocity(8);
}
Intake1.move_velocity(0);
Intake2.move_velocity(0);
}
void SlowSpinOut()
{
while (master.get_digital(DIGITAL_A))
{
  Intake1.move_velocity(-8);
  Intake2.move_velocity(-8);
}
Intake1.move_velocity(0);
Intake2.move_velocity(0);
}
int IntakeRun(void*)
{

while(1)
{
  if(master.get_digital(DIGITAL_L1))
  {
    SpinIn();
  }
else if (master.get_digital(DIGITAL_L2))
{
  SpinOut();
}
pros::delay(10);
}
return 0;
}
