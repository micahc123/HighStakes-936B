#include "main.h"
#include "setup.h"
#include "functions.h"



void disabled() {}

void competition_initialize() {}


void opcontrol() {
    while (true) {
        movement();
        pneumatics();
        intake();
        climbing();
        pros::delay(10);
    }
}