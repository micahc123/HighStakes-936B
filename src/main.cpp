#include "main.h"
#include "globals.h"

using namespace subsystems;

void initialize() {
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
    while (true) {
        movement.tank_drive(master.get_analog(ANALOG_LEFT_Y), master.get_analog(ANALOG_RIGHT_Y));
        pneumatics.run();
        intake.run();
        roller.run();
        wall.run();

        pros::delay(20);
    }
}