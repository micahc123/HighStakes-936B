#include "robot/wall.h"
#include "setup.h"
#include "globals.h"

void wall() {
    bool isWallForwardButtonPressed = master.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
    bool isWallBackwardButtonPressed = master.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
    
    if (isWallForwardButtonPressed) {
        wallMotor.move_voltage(6000);
        
        pros::c::optical_rgb_s_t rgb = colorSensor.get_rgb();
        
        if ((rgb.red > 200 && rgb.green < 100 && rgb.blue < 100) || 
            (rgb.blue > 200 && rgb.green < 100 && rgb.red < 100)) {
                intakeMotor.move_voltage(0);
                intakeToggle = false;
        }
    } else if (isWallBackwardButtonPressed) {
        wallMotor.move_voltage(-6000);
    } else {
        wallMotor.move_voltage(0);
    }
}