#include "main.h"
#include "setup.h"
#include "robot/movement.h"
#include "robot/pneumatics.h"
#include "robot/intake.h"
#include "robot/roller.h"
#include "robot/wall.h"
#include "globals.h" // Include the globals header

// Remove the following line from main.cpp
// bool pistonToggle = false, intakeToggle = false, climbingToggle = false, rollerToggle = false, wallToggle = false;

void disabled() {}

void competition_initialize() {}

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