#include "main.h"
#define LeftFrontPort 7
#define LeftBackPort 10
#define RightFrontPort 2
#define RightBackPort 1
#define RampPort 4
#define LiftPort 3
#define Intake1Port 6
#define Intake2Port 5

pros::Controller master (pros::E_CONTROLLER_MASTER);
pros::Motor LeftFront (LeftFrontPort, MOTOR_GEARSET_18);
pros::Motor LeftBack (LeftBackPort, MOTOR_GEARSET_18);
pros::Motor RightFront (RightFrontPort, MOTOR_GEARSET_18, true);
pros::Motor RightBack (RightBackPort, MOTOR_GEARSET_18 ,true);
pros::Motor RampMotor (RampPort, MOTOR_GEARSET_36);
pros::Motor LiftMotor (LiftPort, MOTOR_GEARSET_36,true);
pros::Motor Intake1 (Intake1Port, MOTOR_GEARSET_36);
pros::Motor Intake2 (Intake2Port, MOTOR_GEARSET_36,true);
pros::ADIGyro *GyroH;
/*
auto myChassis = ChassisControllerFactory::create(
  7, -2, -1, 10,
  AbstractMotor::gearset::green,
  {4_in, 17_in});
*/
