#include "vex.h"
using namespace vex;

double LF, LB, RF, RB;
double y, x1, x2, y2;
double threshold = 10.0;

bool yactive, x1active, x2active, y2active, turning, strafing;
auto name = "Aarush";
auto sideName = "Red Bottom";

void NextName()
{
  if(name=="Aarush")
    {name = "Bharath";}
  else if(name == "Bharath")
    {name = "Soumil";}
  else if(name == "Soumil")
    {name = "Aarush";}
}
void getSide()
{
  if(side ==0)
  {
    sideName = "Red Bottom";
  }
  else if (side ==1)
  {
    sideName = "Blue Bottom";
  }
  else if (side ==2)
  {
    sideName = "Red Top";
  }
  else if (side ==3)
  {
    sideName = "Blue Top";
  }
  else if (side == 4)
  {
    sideName = "None";
  }
}
void Default()
{
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(color::white);
  Brain.Screen.setPenColor(color::blue);
  Brain.Screen.setFont(mono20);
  Brain.Screen.drawRectangle(25, 25, 50, 50);
  Brain.Screen.drawRectangle(25, 125, 50, 50);
  Brain.Screen.setPenColor(color::red);
  Brain.Screen.drawRectangle(400, 25, 50, 50);
  Brain.Screen.drawRectangle(400, 125, 50, 50);

  Brain.Screen.drawRectangle(150, 150,  50, 50);
  Brain.Screen.drawRectangle(250, 150, 50, 50);

  Brain.Screen.setPenColor(color::black);
  Brain.Screen.drawRectangle(200, 25, 50, 50);
  if(setStone)
  {
    Brain.Screen.drawRectangle(150, 150, 50, 50, color::black);
  }
  Brain.Screen.setCursor(5, 1);
  Brain.Screen.print("Blue Top");
  Brain.Screen.setCursor(10,  1);
  Brain.Screen.print("Blue Bottom");
  Brain.Screen.setCursor(5, 39);
  Brain.Screen.print("Red Top");
  Brain.Screen.setCursor(10, 37);
  Brain.Screen.print("Red Bottom");
  Brain.Screen.setCursor(5, 20);
  Brain.Screen.print("User:");
  Brain.Screen.setCursor(6, 20);
  Brain.Screen.print(name);
  Brain.Screen.setCursor(11, 14);
  Brain.Screen.print("Confirm User");
  Brain.Screen.setCursor(11, 25);
  Brain.Screen.print("Run");
  Brain.Screen.setCursor(7, 20);
  getSide();
  Brain.Screen.print(sideName);
}
void SetInStone()
{
  setStone = true;
  if(name=="Soumil")
  {
    Controller1.ButtonL2.pressed(SpinInSoumil);
Controller1.ButtonL1.pressed(SpinOutSoumil);
  }
  else
  {
    Controller1.ButtonL1.pressed(SpinIn);
Controller1.ButtonL2.pressed(SpinOut);
  }
  thread Rampthread = thread(RampMotorRun);
Controller1.ButtonA.pressed(SlowSpinOut);
Controller1.ButtonY.pressed(SlowSpinIn);
Controller1.ButtonR1.pressed(LiftUp);
Controller1.ButtonR2.pressed(LiftDown);
//Controller1.ButtonUp.pressed(RampTo90);
//Controller1.ButtonDown.pressed(RampToStart);
thread PrintToController = thread(toController);
thread slowDriver = thread(SlowDrive);
Controller1.ButtonRight.pressed(IncreaseSensitivity);
Controller1.ButtonLeft.pressed(DecreaseSensitivity);
  
}
void ScreenClick()
{
  
  int x = Brain.Screen.xPosition();
  int y = Brain.Screen.yPosition();
  
  if(x >=25 && x <=75)
    {
      if(y>=25 && y <= 75)
      {
        side = 3;
        Default();  
        Brain.Screen.drawRectangle(25, 25, 50, 50, color::blue); 
      }
      if(y>=125 && y <= 175)
      {
        side = 1;
        Default();
        Brain.Screen.drawRectangle(25, 125, 50, 50, color::blue);
      }
    }
  else if(x >= 400 && x <= 450)
  {
    if(y>=25 && y <= 75)
    {
      side = 2;
      Default();
        Brain.Screen.drawRectangle(400, 25, 50, 50, color::red);
    }
    if(y>=125 && y <= 175)
      {
        side = 0;
        Default();
        Brain.Screen.drawRectangle(400, 125, 50, 50, color::red);
      }
  }
  else if(x>=200 && x <=250)
  {
    if(y>=25 && y <=75 && !setStone)
    {
      NextName();
      Default();
    }
  }
  else if(y >=150 && y <=200)
  {
    if(x>=150 && x<=200 && !setStone)
    {
      SetInStone();
      Default();
    }
    else if (x>=250 && x <=300)
    {
      if(side == 4)
      {
          Brain.Screen.clearScreen();
          autonomous();
      }
    else
    {
      Brain.Screen.clearScreen();
      Brain.Screen.setFillColor(color::white);
        Brain.Screen.setPenColor(color::black);
      Brain.Screen.setFont(propXXL);
      Brain.Screen.setCursor(2, 2);
      int z = 0;
      for(int x = 5; x>0;x--)
      {
        z = x;
        Brain.Screen.clearLine(2);
        Brain.Screen.print(z);
        Brain.Screen.render();
       task::sleep(1000);
      }      
      autonomous();
      Default();
    }
    }
  }
    Brain.Screen.render();
}
void usercontrol(void) {
  Default();
Brain.Screen.pressed(ScreenClick);
while (1) {
  if(setStone && autonomousRan)
  {
    while(1)
    {
      LF = 0;
LB = 0;
RF = 0;
RB = 0;
y  =  DriveScalar*Controller1.Axis3.position();
x1 = DriveScalar*Controller1.Axis4.position();
x2 = DriveScalar*Controller1.Axis1.position();
y2 = DriveScalar*Controller1.Axis2.position();
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
   if(!SlowDriveRunning)
   {
   LeftFront.spin(fwd, LF, pct);
     LeftBack.spin(fwd, LB, pct);
     RightFront.spin(fwd, RF, pct);
     RightBack.spin(fwd, RB, pct);
task::sleep(20);
}
else{
  task::sleep(20);
}
}
    }
    task::sleep(20);
  }

}
