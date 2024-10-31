#ifndef SETUP_H
#define SETUP_H
#include "main.h"
#include "lemlib/api.hpp"

// Ports
#define PNEUMATICS_PORT 'H'    
#define LEFT_MOTOR_1 1
#define LEFT_MOTOR_2 3
#define LEFT_MOTOR_3 6
#define RIGHT_MOTOR_1 2
#define RIGHT_MOTOR_2 4
#define RIGHT_MOTOR_3 5
#define INTAKE_MOTOR 7
#define ROLLER_MOTOR 8
#define WALL_MOTOR 11

pros::Motor leftFrontMotor(LEFT_MOTOR_1, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftBackMotor(LEFT_MOTOR_2, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftTopMotor(LEFT_MOTOR_3, pros::E_MOTOR_GEAR_RED);
pros::Motor rightFrontMotor(RIGHT_MOTOR_1, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightBackMotor(RIGHT_MOTOR_2, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightTopMotor(RIGHT_MOTOR_3, pros::E_MOTOR_GEAR_RED);
pros::Optical colorSensor(1);  
pros::MotorGroup leftMotors({leftFrontMotor, leftBackMotor, leftTopMotor});
pros::MotorGroup rightMotors({rightFrontMotor, rightBackMotor, rightTopMotor});

pros::Motor intakeMotor(INTAKE_MOTOR);
pros::Motor rollerMotor(ROLLER_MOTOR);
pros::Motor wallMotor(WALL_MOTOR);

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
    30,   // kP - Increase for more aggressive response
    0,    // kI - Keep at 0
    20,   // kD - Increase for better stability at high speeds
    3,    // antiWindup
    1,    // smallErrorRange
    100,  // smallErrorTimeout
    3,    // largeErrorRange
    500,  // largeErrorTimeout
    20    // slew rate - Increase for faster acceleration
);

lemlib::Chassis chassis(    
    drivetrain,    
    controller,    
    controller,
    sensors
);

#endif