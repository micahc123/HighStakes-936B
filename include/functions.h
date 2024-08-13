#include "main.h"
#include "setup.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

bool pistonToggle = false;
bool intakeToggle = false;
bool climbingToggle = false;

void pneumatics()
{
    bool isPistonButtonPressed = master.getDigital(ControllerDigital::A);
    
    if (isPistonButtonPressed) {
        pistonToggle = !pistonToggle;
        while (master.getDigital(ControllerDigital::A)) {
            pros::delay(1);
        }
    }
    
    piston.set_value(pistonToggle ? 1 : 0);
}

void intake()
{
    bool isIntakeButtonPressed = master.getDigital(ControllerDigital::R1);
    
    if (isIntakeButtonPressed) {
        intakeToggle = !intakeToggle;
        while (master.getDigital(ControllerDigital::R1)) {
            pros::delay(1);
        }
    }
    
    if (intakeToggle) {
        intakeMotor1.moveVoltage(6000);
        intakeMotor2.moveVoltage(-6000);
    } else {
        intakeMotor1.moveVoltage(0);
        intakeMotor2.moveVoltage(0);
    }
}

void climbing()
{
    bool isClimbingButtonPressed = master.getDigital(ControllerDigital::L1);
    
    if (isClimbingButtonPressed) {
        climbingToggle = !climbingToggle;
        while (master.getDigital(ControllerDigital::L1)) {
            pros::delay(1);
        }
    }
    
    if (climbingToggle) {
        climbingMotor1.moveVoltage(6000);
        climbingMotor2.moveVoltage(6000);
    } else {
        climbingMotor1.moveVoltage(0);
        climbingMotor2.moveVoltage(0);
    }
}

void movement(){
    double left = -master.getAnalog(ControllerAnalog::leftY);
    double right = master.getAnalog(ControllerAnalog::rightY);

    if (left == 0 && right == 0) {
        leftMotors.setBrakeMode(AbstractMotor::brakeMode::hold);
        rightMotors.setBrakeMode(AbstractMotor::brakeMode::hold);
    } else {
        drive->getModel()->tank(left, right);
        
        leftMotors.setBrakeMode(AbstractMotor::brakeMode::coast);
        rightMotors.setBrakeMode(AbstractMotor::brakeMode::coast);
    }
}

#endif