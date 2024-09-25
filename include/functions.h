#include "main.h"
#include "setup.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

bool pistonToggle = false, intakeToggle = false, climbingToggle = false;

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
    bool isIntakeButtonPressed = master.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    
    if (isIntakeButtonPressed) {
        intakeToggle = !intakeToggle;
        while (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            pros::delay(1);
        }
    }
    
    if (intakeToggle) {
        intakeMotor1.move_voltage(6000);
        intakeMotor2.move_voltage(-6000);
    } else {
        intakeMotor1.move_voltage(0);
        intakeMotor2.move_voltage(0);
    }
}

void climbing()
{
    bool isClimbingButtonPressed = master.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
    
    if (isClimbingButtonPressed) {
        climbingToggle = !climbingToggle;
        while (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            pros::delay(1);
        }
    }
    
    if (climbingToggle) {
        climbingMotor1.move_voltage(6000);
        climbingMotor2.move_voltage(6000);
    } else {
        climbingMotor1.move_voltage(0);
        climbingMotor2.move_voltage(0);
    }
}

void movement(){
    double left = -master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    double right = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    chassis.tank(left, right, 0.05);
}

#endif