#include "main.h"
#include "globals.h"

using namespace subsystems;

void initialize() {
    chassis.calibrate();
    chassis.setPose(0, 0, 0);
    AutonSelector::init();
    DonutSelector::init();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
    AUTON_ROUTINE selected = AutonSelector::get_selected_auton();
    auton.run_auton(selected);
}

void opcontrol() {
    while (true) {
        movement.tank_drive(master.get_analog(ANALOG_LEFT_Y), master.get_analog(ANALOG_RIGHT_Y));
        clamp.run();
        intake.run();
        roller.run();
        wall.run();

        if (master.get_digital_new_press(DIGITAL_DOWN)) {
            DonutSelector::show();
        }

        pros::delay(20);
    }
}