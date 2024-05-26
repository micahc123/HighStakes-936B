// robot_functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "main.h"


auto drive = ChassisControllerBuilder()
    .withMotors(leftMotors, rightMotors) 
    .withDimensions(AbstractMotor::gearset::blue, {{4_in, 10_in}, imev5BlueTPR})
    .withOdometry()
    .buildOdometry();

Controller master;
pros::ADIDigitalOut piston(PNEUMATICS_PORT);

void pneumatics()
{
  if(master.getDigital(ControllerDigital::A)){
      piston.set_value(true);
    }
    else if(master.getDigital(ControllerDigital::B)){
      piston.set_value(false);
    }
}

void intake(){

  if(master.getDigital(ControllerDigital::R1)){
      intakeMotor1.moveVoltage(12000);
      intakeMotor2.moveVoltage(-12000);
    }
    else if(master.getDigital(ControllerDigital::R2)){
      intakeMotor1.moveVoltage(-12000);
      intakeMotor2.moveVoltage(12000);
    }
    else{
      intakeMotor1.moveVoltage(0);
      intakeMotor2.moveVoltage(0);
    }
}

void climbing(){

  if(master.getDigital(ControllerDigital::L1)){
      climbingMotor1.moveVoltage(6000);
      climbingMotor2.moveVoltage(-6000);
    }
    else if(master.getDigital(ControllerDigital::L2)){
      climbingMotor1.moveVoltage(-6000);
      climbingMotor2.moveVoltage(6000);
    }
    else{
      climbingMotor1.moveVoltage(100); 
      climbingMotor2.moveVoltage(-100); 
    }
}
void movement(){
    //movement values
    double left = -master.getAnalog(ControllerAnalog::leftY);
    double right = master.getAnalog(ControllerAnalog::rightY);


    //base movement
    drive->getModel()->tank(left, right);

}
#endif // ROBOT_FUNCTIONS_H