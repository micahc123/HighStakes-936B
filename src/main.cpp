#include "main.h"
#include "setup.h"
#include "robot/movement.h"
#include "robot/pneumatics.h"
#include "robot/intake.h"
#include "robot/roller.h"
#include "robot/wall.h"
#include "globals.h" 

void disabled() {}

void initialize() {
    chassis.calibrate();
    chassis.setPose(0, 0, 0);
}

void opcontrol() {
    while (true) {
        movement();
        pneumatics();
        intake();
        roller();
        wall();
        pros::delay(10);
    }
}