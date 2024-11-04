#include "globals.h"

bool pistonToggle = false;
bool intakeToggle = false;
bool climbingToggle = false;
bool rollerToggle = false;
bool wallToggle = false;

pros::Motor leftFrontMotor(LEFT_MOTOR_1, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftBackMotor(LEFT_MOTOR_2, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftTopMotor(LEFT_MOTOR_3, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightFrontMotor(RIGHT_MOTOR_1, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightBackMotor(RIGHT_MOTOR_2, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightTopMotor(RIGHT_MOTOR_3, pros::E_MOTOR_GEAR_BLUE);
pros::MotorGroup leftMotors({leftFrontMotor, leftBackMotor});
pros::MotorGroup rightMotors({rightFrontMotor, rightBackMotor});

pros::Controller master(pros::E_CONTROLLER_MASTER);

lemlib::Drivetrain drivetrain {
    &leftMotors,
    &rightMotors,
    10.5, // track width
    lemlib::Omniwheel::NEW_4, // wheel type
    360,  // rpm
    2     // chase power
};

lemlib::OdomSensors sensors {
    nullptr, 
    nullptr, 
    nullptr, 
    nullptr, 
    nullptr 
};

lemlib::ControllerSettings controller(
    10,   // kP
    0,    // kI
    20,   // kD
    3,    // anti-windup
    1,    // small error range
    100,  // small error timeout
    3,    // large error range
    500,  // large error timeout
    20    // slew rate
);

lemlib::Chassis chassis(
    drivetrain,
    controller,
    controller,
    sensors
);

subsystems::Movement movement(&chassis);
subsystems::Clamp clamp(CLAMP_PORT_LEFT, CLAMP_PORT_RIGHT);
subsystems::Roller roller(ROLLER_MOTOR);
subsystems::Intake intake(INTAKE_MOTOR, INTAKE_COLOR_SENSOR_PORT, INTAKE_DISTANCE_SENSOR_PORT);
subsystems::Wall wall(WALL_MOTOR);
subsystems::Selector selector(&intake);
subsystems::Doinker doinker(DOINKER_PORT);
