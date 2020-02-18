#include "vex.h"

double DriveScalar = 0.55;

double RampScalar = 0.5;

double LiftScalar = 0.8;

double IntakeScalar = 1.0;

bool RampRunning = false;

double Circumference = 12.25;
double StrafeDistance = 10;
double DegreesToRotate;
double TurnDegrees = 63;
double Orientation = 0;
double GoalDegrees;
double kP = 1.6;
double kI = 0.003;
double kD = 0.1;
double kPLeft = 1.65;
double error, integral, derivative, previousError;
bool To90Running, To0Running;
double RightAngle = 61;
double LeftAngle = -61;
int side = 4;
bool setStone = false;
bool autonomousRan = false;