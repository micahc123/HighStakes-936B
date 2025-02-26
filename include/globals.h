#ifndef GLOBALS_H
#define GLOBALS_H

#include "pros/rtos.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "pros/adi.hpp"
#include "robot/movement.h"
#include "robot/clamp.h"
#include "robot/selector.h"
#include "robot/intake.h"
#include "robot/wall.h"
#include "robot/doinker.h"
#include "lemlib/api.hpp"



//ports
#define CLAMP_PORT 'G'
#define DOINKER_PORT 'H'    
#define LEFT_MOTOR_1 1
#define LEFT_MOTOR_2 2
#define LEFT_MOTOR_3 3
#define RIGHT_MOTOR_1 7
#define RIGHT_MOTOR_2 8
#define RIGHT_MOTOR_3 9
#define INTAKE_MOTOR 6
#define WALL_MOTOR_1 18
#define WALL_MOTOR_2 10
#define INTAKE_COLOR_SENSOR_PORT 1
#define WALL_ROTATION_SENSOR 18


//controller
#define DIGITAL_L1 pros::E_CONTROLLER_DIGITAL_L1
#define DIGITAL_L2 pros::E_CONTROLLER_DIGITAL_L2
#define DIGITAL_R1 pros::E_CONTROLLER_DIGITAL_R1
#define DIGITAL_R2 pros::E_CONTROLLER_DIGITAL_R2
#define DIGITAL_A pros::E_CONTROLLER_DIGITAL_A
#define DIGITAL_B pros::E_CONTROLLER_DIGITAL_B
#define DIGITAL_X pros::E_CONTROLLER_DIGITAL_X
#define DIGITAL_Y pros::E_CONTROLLER_DIGITAL_Y
#define DIGITAL_DOWN pros::E_CONTROLLER_DIGITAL_DOWN
#define DIGITAL_UP pros::E_CONTROLLER_DIGITAL_UP
#define ANALOG_LEFT_Y pros::E_CONTROLLER_ANALOG_LEFT_Y
#define ANALOG_RIGHT_X pros::E_CONTROLLER_ANALOG_RIGHT_X

// toggle variables
extern bool pistonToggle;
extern bool intakeToggle;
extern bool climbingToggle;
extern bool wallToggle;

namespace subsystems {
    class Movement;
    class Clamp;
    class Roller;
    class Intake;
    class Wall;
    class Doinker;
    class Selector;
    class Auton;
}


// motors
extern pros::Motor leftFrontMotor;
extern pros::Motor leftBackMotor;
extern pros::Motor rightFrontMotor;
extern pros::Motor rightBackMotor;
extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;



extern pros::Controller master;
extern pros::ADIDigitalOut piston;

// subsystem
extern subsystems::Movement movement;
extern subsystems::Clamp clamp;
extern subsystems::Wall wall;
extern subsystems::Intake intake;
extern subsystems::Selector selector;
extern subsystems::Doinker doinker;
extern subsystems::Auton auton;
// chassis
extern lemlib::Drivetrain drivetrain;

extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings controller;
extern lemlib::Chassis chassis;

#endif // GLOBALS_H