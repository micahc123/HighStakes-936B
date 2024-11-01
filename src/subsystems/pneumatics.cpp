#include "robot/pneumatics.h"
#include "setup.h"

void pneumatics() {
    bool isPistonButtonPressed = master.get_digital(pros::E_CONTROLLER_DIGITAL_A);
    
    if (isPistonButtonPressed) {
        pistonToggle = !pistonToggle;
        while (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
            pros::delay(1);
        }
    }
    
    piston.set_value(pistonToggle ? 1 : 0);
}