/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"
#include "Autonomous.h"
#include "Usercontrol.h"
#include "PreAutonomous.h"
#include "Constants.h"
#include "Sensitivity.h"
#include "Lift_User.h"
#include "Ramp_User.h"
#include "Intake_User.h"
#include "ToController.h"
#include "Intake_Auto.h"
#include "Drive_Auto.h"
#include "Ramp_Auto.h"
#include "Turning_Auto.h"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)