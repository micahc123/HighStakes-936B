#include "robot/intake.h"
#include "setup.h"

void intake() {
    bool isIntakeForwardButtonPressed = master.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    bool isIntakeBackwardButtonPressed = master.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
    
    if (isIntakeForwardButtonPressed) {
        intakeMotor.move_voltage(12000);
    } else if (isIntakeBackwardButtonPressed) {
        intakeMotor.move_voltage(-12000);
    } else {
        intakeMotor.move_voltage(0);
    }
}