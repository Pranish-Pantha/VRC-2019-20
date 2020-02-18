#include "vex.h"
using namespace vex;
// A global instance of competition
competition Competition;

  
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  preAuto(); //Preautonomous Function
  //usercontrol();

  while (true) {
    wait(100, msec);
  }
}
