#include "vex.h"
using namespace vex;

void toController()
{
  while(1)
  {
Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1,1);
  double rampTemp = RampMotor.temperature(percent);
  double rampCurrent = RampMotor.current();
  double brainCapacity = Brain.Battery.capacity();
  double rampTorque = RampMotor.torque(Nm);
  double brainVoltage = Brain.Battery.voltage();
  Controller1.Screen.print("Ramp Temp %f", rampTemp);
  Controller1.Screen.newLine();
  Controller1.Screen.print("Ramp Current %f", rampCurrent);
  Controller1.Screen.newLine();
  Controller1.Screen.print("Battery capacity %f", brainCapacity);
  Controller1.Screen.newLine();
  Controller1.Screen.print("Ramp Torque %f", rampTorque);
  Controller1.Screen.newLine();
  Controller1.Screen.print("Battery Voltage %f", brainVoltage);
 this_thread::sleep_for(400);
   }
}