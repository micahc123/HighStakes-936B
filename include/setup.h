#ifndef SETUP_H
#define SETUP_H
#include "main.h"
#include "lemlib/api.hpp"

// Ports

#define PNEUMATICS_PORT 'H'    
#define LEFT_MOTOR_1 1
#define LEFT_MOTOR_2 3
#define RIGHT_MOTOR_1 2
#define RIGHT_MOTOR_2 4
#define INTAKE_MOTOR 5
#define ROLLER_MOTOR 6
#define WALL_MOTOR 11


pros::Motor leftFrontMotor(LEFT_MOTOR_1,  pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftBackMotor(LEFT_MOTOR_2, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightFrontMotor(RIGHT_MOTOR_1, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightBackMotor(RIGHT_MOTOR_2, pros::E_MOTOR_GEAR_BLUE);
pros::Optical colorSensor(1);  
pros::MotorGroup leftMotors({leftFrontMotor, leftBackMotor});
pros::MotorGroup rightMotors({rightFrontMotor, rightBackMotor});

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
    20,   // kP (proportional gain)
    0,    // kI (integral gain)
    10,   // kD (derivative gain)
    3,    // antiWindup
    1,    // smallErrorRange
    100,  // smallErrorTimeout
    3,    // largeErrorRange
    500,  // largeErrorTimeout
    10    // slew rate
);

lemlib::Chassis chassis(    
    drivetrain,    
    controller,    
    controller,
    sensors
);


#endif