#include "main.h"
#include "globals.h"

using namespace subsystems;

void initialize() {
    chassis.calibrate();
    chassis.setPose(0, 0, 0);
    selector.init();

}

void disabled() {}

void competition_initialize() {}

void autonomous() {
    auton.run_auton(auton.get_selected_auton());
}

void opcontrol() {
    while (true) {
        movement.drive(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
        clamp.run();
        intake.run();
        wall.run();
        doinker.run();
        pros::delay(10);
    }
}