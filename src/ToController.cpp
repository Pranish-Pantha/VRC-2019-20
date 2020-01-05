#include "vex.h"
using namespace vex;

void toController()
{
  while(1)
  {
  Controller1.Screen.setCursor(3,1);
  Controller1.Screen.clearLine();
  Controller1.Screen.print(GyroH.rotation(degrees));
 this_thread::sleep_for(400);
   }
}