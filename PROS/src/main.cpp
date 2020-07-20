#include "main.h"
#include "okapi/api.hpp"
#include "okapi/impl/chassis/controller/chassisControllerFactory.hpp"
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
 #define GYRO_SENSOR ('H')
void initialize() {
	GyroH = new pros::ADIGyro(GYRO_SENSOR);
	GyroH ->reset();
	LeftFront.set_brake_mode(MOTOR_BRAKE_HOLD);
	LeftBack.set_brake_mode(MOTOR_BRAKE_HOLD);
	RightFront.set_brake_mode(MOTOR_BRAKE_HOLD);
	RightBack.set_brake_mode(MOTOR_BRAKE_HOLD);
	RampMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
	LiftMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
	Intake1.set_brake_mode(MOTOR_BRAKE_HOLD);
	Intake2.set_brake_mode(MOTOR_BRAKE_HOLD);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

void autonomous() {}
/*
  auto profileController = AsyncControllerFactory::motionProfile(
    1.0,  // Maximum linear velocity of the Chassis in m/s
    2.0,  // Maximum linear acceleration of the Chassis in m/s/s
    10.0, // Maximum linear jerk of the Chassis in m/s/s/s
    myChassis // Chassis Controller
  );
  */
  /*
  myChassis.moveDistance(3_in);
  profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0_ft, 0_deg}}, "A");
 profileController.setTarget("A");
 profileController.waitUntilSettled();
 */
/**
prosv5 conduct new <path_to_project>
prosv5 make
prosv5 upload
prosv5 terminal
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

 double LF, LB, RF, RB;
 double y, x1, x2, y2;
 double threshold = 10.0;
 bool yactive, x1active, x2active, y2active, turning, strafing;

void opcontrol() {
	/*
	thread Rampthread = thread(RampMotorRun);

thread autoRampthread = thread(AutoRampRun);
thread PrintToController = thread(toController);


thread Liftthread = thread(LiftRun);
Controller1.ButtonRight.pressed(IncreaseSensitivity);
Controller1.ButtonLeft.pressed(DecreaseSensitivity);
	*/
  /*
  int i = 0;
  pros::task_fn_t (IntakeRun);
  pros::task_t a_task = pros::c::task_create(IntakeRun, (void*)"PROS", TASK_PRIORITY_DEFAULT,
                               TASK_STACK_DEPTH_DEFAULT, "My Task");
  pros::Task my_task (IntakeRun,NULL,TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "");
  pros::c::task_create(IntakeRun,NULL,TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "");
*/
  while (true) {
    //master.print(1, 1, "%d", GyroH ->get_value());
    master.print(3,3, "%d", LF);
LF = 0;
LB = 0;
RF = 0;
RB = 0;
y  =  DriveScalar*master.get_analog(ANALOG_LEFT_Y);
x1 = DriveScalar*master.get_analog(ANALOG_LEFT_X);
x2 = DriveScalar*master.get_analog(ANALOG_RIGHT_X);
y2 = DriveScalar*master.get_analog(ANALOG_RIGHT_Y);
threshold = 10.0;
yactive = false;
   x1active = false;
   x2active = false;
   y2active = false;
   turning = false;
if( fabs(y) > threshold)
       {
         LF += y;
         LB += y;
         RF += y;
         RB += y;
         yactive = true;
       }
     if(fabs(x1)>threshold)
     {
         LF += x1;
         LB += x1;
         RF -= x1;
         RB -= x1;
         x1active = true;
         turning = true;
     }
     if ( fabs(y2) > threshold)
     {
         LF += y2;
         LB += y2;
         RF += y2;
         RB += y2;
         y2active = true;
     }
     if ( fabs(x2) > threshold)
     {
         LF += x2;
         LB -= x2;
         RF -= x2;
         RB += x2;
         x2active = true;
         strafing = true;

     }
     else{
       strafing = false;
       //GyroH.setHeading(0, deg);
         error = 0;
   derivative = 0;
   previousError = 0;
     }
   if((yactive&&(x2active||y2active))||(x1active&&(y2active||x2active)))
     {
       LF = LF * DriveScalar;
       LB = LB * DriveScalar;
       RF = RF * DriveScalar;
       RB = RB * DriveScalar;
     }
   if(strafing && !turning)
   {
     /*
       error = GyroH.heading();
       derivative =  error- previousError;
       previousError = error;
     LF += kPStrafe*error + kDStrafe * derivative;
     LB -= kPStrafe*error + kDStrafe * derivative;
     RF -= kPStrafe*error + kDStrafe * derivative;
     RB += kPStrafe*error + kDStrafe * derivative;
     */
   }
	 LF = LF *2;
	 LB = LB *2;
	 RF = RF *2;
	 RB = RB *2;
	 	LeftFront.move_velocity(LF);
		LeftBack.move_velocity(LB);
		RightFront.move_velocity(RF);
		RightBack.move_velocity(RB);
		pros::delay(20);
	}
}
