#include "main.h"
double DriveScalar = 0.7;

double RampScalar = 0.4;

double LiftScalar = 0.5;

double IntakeScalar = 0.5;

bool RampRunning = false;

double Circumference = 11.7;
double DegreesToRotate;
double TurnDegrees = 64;
double Orientation = 0;
double GoalDegrees;
double kP = 1.45;
double kI = 0.003;
double kD = 0.1;
double error, integral, derivative, previousError;
bool To90Running, To0Running;
double RightAngle = 61;
double LeftAngle = -61;
