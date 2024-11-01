#include "robot/roller.h"
#include "setup.h"

void roller() {
    bool isRollerButtonPressed = master.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
    if (isRollerButtonPressed) {
        rollerToggle = !rollerToggle;
        while (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            pros::delay(1);
        }
    }
    
    if (rollerToggle) {
        rollerMotor.move_voltage(12000);
    } else {
        rollerMotor.move_voltage(0);
    }
}