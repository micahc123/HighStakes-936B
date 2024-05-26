// Purpose: Contains all the functions used in the robot code

#include "main.h"
#include "setup.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H




bool wasPistonPressed = false; 
bool pistonState = false; 
void pneumatics()
{
    bool isPistonPressed = master.getDigital(ControllerDigital::A);
    if(isPistonPressed && !wasPistonPressed){
        pistonState = !pistonState;
        piston.set_value(pistonState ? 1 : 0);
    }
    wasPistonPressed = isPistonPressed;
}
bool wasIntakePressed = false; 
bool intakeState = false; 

void intake()
{
    bool isIntakePressed = master.getDigital(ControllerDigital::R1);

    if(isIntakePressed && !wasIntakePressed){
        intakeState = !intakeState;
    }
    if(intakeState){
        intakeMotor1.moveVoltage(6000);
        intakeMotor2.moveVoltage(-6000);
    }
    else{
        intakeMotor1.moveVoltage(0);
        intakeMotor2.moveVoltage(0);
    }

    wasIntakePressed = isIntakePressed;
}

bool wasClimbing = false; 
bool climbState = false; 

void climbing()
{
    bool isClimbingPressed = master.getDigital(ControllerDigital::L1);

    if(isClimbingPressed && !wasClimbing){
        climbState = !climbState;
    }

    if(climbState){
        climbingMotor1.moveVoltage(3000);
        climbingMotor2.moveVoltage(-3000);
    }
    else{
        climbingMotor1.setBrakeMode(AbstractMotor::brakeMode::hold);
        climbingMotor2.setBrakeMode(AbstractMotor::brakeMode::hold);
    }

    wasClimbing = isClimbingPressed;
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