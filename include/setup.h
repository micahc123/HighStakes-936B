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

pros::Motor leftFrontMotor(LEFT_MOTOR_1,  pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftBackMotor(LEFT_MOTOR_2, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightFrontMotor(RIGHT_MOTOR_1, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightBackMotor(RIGHT_MOTOR_2, pros::E_MOTOR_GEAR_BLUE);


pros::MotorGroup leftMotors({leftFrontMotor, leftBackMotor});
pros::MotorGroup rightMotors({rightFrontMotor, rightBackMotor});

pros::Motor intakeMotor1(INTAKE_MOTOR_1);
pros::Motor intakeMotor2(INTAKE_MOTOR_2);
pros::Motor climbingMotor1(CLIMBING_MOTOR_1);
pros::Motor climbingMotor2(CLIMBING_MOTOR_2);

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::ADIDigitalOut piston(PNEUMATICS_PORT);


lemlib::Drivetrain drivetrain {
    &leftMotors,
    &rightMotors,
    10.5, //track width
    lemlib::Omniwheel::NEW_4, //wheel
    600, //rpm
    2 //drift
};
lemlib::OdomSensors sensors {
    nullptr, 
    nullptr, 
    nullptr, 
    nullptr, 
    nullptr 
};

lemlib::ControllerSettings controller(
    10,   // kP (proportional gain)
    0,    // kI (integral gain)
    3,    // kD (derivative gain)
    3,    // antiWindup
    1,    // smallErrorRange
    100,  // smallErrorTimeout
    3,    // largeErrorRange
    500,  // largeErrorTimeout
    5     // slew rate
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