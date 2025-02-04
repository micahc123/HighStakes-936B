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
        
        if (master.get_digital_new_press(DIGITAL_DOWN)) {
            auton.test_lateral();
        }
        if (master.get_digital_new_press(DIGITAL_RIGHT)) {
            // Test angular controller
            auton.test_angular();
        }
        
        clamp.run();
        intake.run();
        wall.run();
        doinker.run();
        selector.update();
        pros::delay(10);
    }
}