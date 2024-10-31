#include "main.h"
#include "setup.h"

bool pistonToggle = false, intakeToggle = false, climbingToggle = false, rollerToggle = false, wallToggle = false;


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

void pneumatics()
{
    bool isPistonButtonPressed = master.get_digital(pros::E_CONTROLLER_DIGITAL_A);
    
    if (isPistonButtonPressed) {
        pistonToggle = !pistonToggle;
        while (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
            pros::delay(1);
        }
    }
    
    piston.set_value(pistonToggle ? 1 : 0);
}
void intake()
{
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

void movement(){
    double leftY = -master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    double rightY = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    chassis.tank(2.0 * leftY, 2.0 * rightY);
}
 