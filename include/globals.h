#ifndef GLOBALS_H
#define GLOBALS_H

#include "pros/rtos.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "pros/adi.hpp"
#include "robot/movement.h"
#include "robot/pneumatics.h"
#include "robot/roller.h"
#include "robot/intake.h"
#include "robot/wall.h"
#include "lemlib/api.hpp"

// Port Definitions
#define PNEUMATICS_PORT 'H'    
#define LEFT_MOTOR_1 2
#define LEFT_MOTOR_2 15
#define LEFT_MOTOR_3 20
#define RIGHT_MOTOR_1 3
#define RIGHT_MOTOR_2 11
#define RIGHT_MOTOR_3 12
#define INTAKE_MOTOR 7
#define ROLLER_MOTOR 8
#define WALL_MOTOR 11

// Controller Definitions
#define DIGITAL_L1 pros::E_CONTROLLER_DIGITAL_L1
#define DIGITAL_L2 pros::E_CONTROLLER_DIGITAL_L2
#define DIGITAL_R1 pros::E_CONTROLLER_DIGITAL_R1
#define DIGITAL_R2 pros::E_CONTROLLER_DIGITAL_R2
#define ANALOG_LEFT_Y pros::E_CONTROLLER_ANALOG_LEFT_Y
#define ANALOG_RIGHT_Y pros::E_CONTROLLER_ANALOG_RIGHT_Y

// Toggle variables
extern bool pistonToggle;
extern bool intakeToggle;
extern bool climbingToggle;
extern bool rollerToggle;
extern bool wallToggle;

// Motor instances
extern pros::Motor leftFrontMotor;
extern pros::Motor leftBackMotor;
extern pros::Motor leftTopMotor;
extern pros::Motor rightFrontMotor;
extern pros::Motor rightBackMotor;
extern pros::Motor rightTopMotor;
extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;

// Controller and peripheral instances
extern pros::Controller master;
extern pros::ADIDigitalOut piston;

// Subsystem instances
extern subsystems::Movement movement;
extern subsystems::Pneumatics pneumatics;
extern subsystems::Roller roller;
extern subsystems::Intake intake;
extern subsystems::Wall wall;

// Chassis instances
extern lemlib::Drivetrain drivetrain;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings controller;
extern lemlib::Chassis chassis;

#endif // GLOBALS_H