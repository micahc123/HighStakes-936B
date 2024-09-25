#ifndef SETUP_H
#define SETUP_H
#include "main.h"
#include "lemlib/api.hpp"

// Ports
#define PNEUMATICS_PORT 'H'
#define LEFT_MOTOR_1 11
#define LEFT_MOTOR_2 12
#define RIGHT_MOTOR_1 1
#define RIGHT_MOTOR_2 2
#define INTAKE_MOTOR_1 9
#define INTAKE_MOTOR_2 10
#define CLIMBING_MOTOR_1 13
#define CLIMBING_MOTOR_2 14

pros::Motor leftMotor1(LEFT_MOTOR_1, pros::E_MOTOR_GEARSET_06, false);
pros::Motor leftMotor2(LEFT_MOTOR_2, pros::E_MOTOR_GEARSET_06, false);
pros::Motor rightMotor1(RIGHT_MOTOR_1, pros::E_MOTOR_GEARSET_06, true);
pros::Motor rightMotor2(RIGHT_MOTOR_2, pros::E_MOTOR_GEARSET_06, true);

pros::MotorGroup leftMotors({leftMotor1, leftMotor2});
pros::MotorGroup rightMotors({rightMotor1, rightMotor2});

pros::Motor intakeMotor1(INTAKE_MOTOR_1);
pros::Motor intakeMotor2(INTAKE_MOTOR_2);
pros::Motor climbingMotor1(CLIMBING_MOTOR_1);
pros::Motor climbingMotor2(CLIMBING_MOTOR_2);

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::ADIDigitalOut piston(PNEUMATICS_PORT);


lemlib::Drivetrain drivetrain {
    &leftMotors,
    &rightMotors,
    10.5, 
    3.25,
    360, 
    1 
};
lemlib::OdomSensors sensors {
    nullptr, 
    nullptr, 
    nullptr, 
    nullptr, 
    nullptr 
};

lemlib::ControllerSettings controller(
    10,
    0,
    3,
    3,
    1,
    100,
    3,
    500,
    5
);

lemlib::Chassis chassis(    
    drivetrain,    
    controller,    
    controller,
    sensors,   
    nullptr,   
    nullptr 

);


#endif