#include "main.h"
#include "functions.h"



void opcontrol() {
  while (true) {

    movement();
    climbing();
    pneumatics();
    intake();
    
    pros::delay(20);
  }
}






void autonomous(){
  nullptr;
}


