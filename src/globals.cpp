#include "globals.h"

bool pistonToggle = false;
bool intakeToggle = false;
bool climbingToggle = false;
bool rollerToggle = false;
bool wallToggle = false;

pros::Motor leftFrontMotor(LEFT_MOTOR_1, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftBackMotor(LEFT_MOTOR_2, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightFrontMotor(RIGHT_MOTOR_1, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightBackMotor(RIGHT_MOTOR_2, pros::E_MOTOR_GEAR_BLUE);
pros::MotorGroup leftMotors({leftFrontMotor, leftBackMotor});
pros::MotorGroup rightMotors({rightFrontMotor, rightBackMotor});

pros::Controller master(pros::E_CONTROLLER_MASTER);

lemlib::Drivetrain drivetrain {
    &leftMotors,
    &rightMotors,
    12.5, // track width
    lemlib::Omniwheel::OLD_4, // wheel type
    300,  // rpm
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
    10,   
    0,   
    20,   
    3,   
    1,   
    100, 
    3,    
    500, 
    20  
);

lemlib::Chassis chassis(
    drivetrain,
    controller,
    controller,
    sensors
);

subsystems::Movement movement(&chassis);
subsystems::Clamp clamp(CLAMP_PORT);
subsystems::Roller roller(ROLLER_MOTOR);
subsystems::Intake intake(INTAKE_MOTOR, INTAKE_COLOR_SENSOR_PORT);
subsystems::Wall wall(WALL_MOTOR);
subsystems::Auton auton(&chassis);
subsystems::Selector selector(&intake, &auton);
subsystems::Doinker doinker(DOINKER_PORT);
