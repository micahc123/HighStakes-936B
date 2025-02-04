#include "globals.h"

bool pistonToggle = false;
bool intakeToggle = false;
bool climbingToggle = false;
bool rollerToggle = false;
bool wallToggle = false;

pros::Motor leftFrontMotor(LEFT_MOTOR_1, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftBackMotor(LEFT_MOTOR_2, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftMiddleMotor(LEFT_MOTOR_3, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightFrontMotor(RIGHT_MOTOR_1, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightMiddleMotor(RIGHT_MOTOR_3, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightBackMotor(RIGHT_MOTOR_2, pros::E_MOTOR_GEAR_BLUE);
pros::MotorGroup leftMotors({leftFrontMotor, leftMiddleMotor, leftBackMotor});
pros::MotorGroup rightMotors({rightFrontMotor,rightMiddleMotor, rightBackMotor});

pros::Controller master(pros::E_CONTROLLER_MASTER);

lemlib::Drivetrain drivetrain {
    &leftMotors,
    &rightMotors,
    12.5, // track width
    lemlib::Omniwheel::NEW_325, // wheel type
    520,  // rpm
    2   //drift
};

lemlib::OdomSensors sensors {
    nullptr, 
    nullptr, 
    nullptr, 
    nullptr, 
    nullptr 
};

lemlib::ControllerSettings controller(
    10,  //
    0,   
    20,   
    3,   
    1,   
    100, 
    3,    
    500, 
    20  
);
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
                                              
);
lemlib::Chassis chassis(
    drivetrain,
    controller,
    angular_controller,
    sensors
);

subsystems::Movement movement(&chassis);
subsystems::Clamp clamp(CLAMP_PORT);
subsystems::Intake intake(INTAKE_MOTOR, INTAKE_COLOR_SENSOR_PORT);
subsystems::Wall wall(WALL_MOTOR_1, WALL_MOTOR_2);
subsystems::Auton auton(&chassis);
subsystems::Selector selector(&intake, &auton);
subsystems::Doinker doinker(DOINKER_PORT);
