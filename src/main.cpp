#include "main.h"
#include "globals.h"

using namespace subsystems;

void initialize() {
    chassis.calibrate();
    chassis.setPose(0, 0, 0);

}

void disabled() {}

void competition_initialize() {}

void autonomous() {
    auton.run_auton(auton.get_selected_auton());
}

void opcontrol() {
    while (true) {
        movement.drive(master.get_analog(ANALOG_LEFT_Y), master.get_analog(ANALOG_RIGHT_Y));
        clamp.run();
        intake.run();
        roller.run();
        wall.run();
        doinker.run();
        pros::delay(10);
    }
}