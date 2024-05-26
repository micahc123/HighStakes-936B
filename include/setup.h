#ifndef SETUP_H
#define SETUO_H
#include "main.h"

//ports
#define PNEUMATICS_PORT 'A'
#define LEFT_MOTOR_1 11
#define LEFT_MOTOR_2 12
#define RIGHT_MOTOR_1 1
#define RIGHT_MOTOR_2 2
#define INTAKE_MOTOR_1 9
#define INTAKE_MOTOR_2 10
#define CLIMBING_MOTOR_1 13
#define CLIMBING_MOTOR_2 14

//motor groups initialized here 
auto leftMotors = MotorGroup({LEFT_MOTOR_1, LEFT_MOTOR_2}); 
auto rightMotors = MotorGroup({RIGHT_MOTOR_1, RIGHT_MOTOR_2});
auto intakeMotor1 = okapi::Motor(INTAKE_MOTOR_1);
auto intakeMotor2 = okapi::Motor(INTAKE_MOTOR_2);
auto climbingMotor1 = okapi::Motor(CLIMBING_MOTOR_1);
auto climbingMotor2= okapi::Motor(CLIMBING_MOTOR_2);


//Controller, pneumatics
Controller master;
pros::ADIDigitalOut piston(PNEUMATICS_PORT);


//Drive
auto drive = ChassisControllerBuilder()
    .withMotors(leftMotors, rightMotors) 
    .withDimensions(AbstractMotor::gearset::blue, {{4_in, 10_in}, imev5BlueTPR})
    .withOdometry()
    .buildOdometry();



#endif