#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftFront = motor(PORT7, ratio18_1, false);
motor LeftBack = motor(PORT10, ratio18_1, false);
motor RightFront = motor(PORT2, ratio18_1, true);
motor RightBack = motor(PORT1, ratio18_1, true);
motor RampMotor = motor(PORT4, ratio36_1, false);
motor LiftMotor = motor(PORT3, ratio36_1, true);
motor IntakeMotor1 = motor(PORT6, ratio36_1, false);
motor IntakeMotor2 = motor(PORT15, ratio36_1, true);
gyro GyroH = gyro(Brain.ThreeWirePort.H);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}