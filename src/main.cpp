#include "main.h"


auto leftMotors = MotorGroup({1, 3, 5});
auto rightMotors = MotorGroup({2, 4, 6});

auto drive = ChassisControllerBuilder()
    .withMotors(leftMotors, rightMotors) 
    .withDimensions(AbstractMotor::gearset::blue, {{4_in, 10_in}, imev5BlueTPR})
    .build();

Controller master;

pros::Rotation rotationSensor(7);

// Tank Drive
void opcontrol() {
  while (true) {
    double left = -master.getAnalog(ControllerAnalog::leftY);
    double right = -master.getAnalog(ControllerAnalog::rightY);

    double theta = rotationSensor.get_position();

    double angleRad = theta * M_PI / 180.0;

    double fieldOrientedLeft = left * cos(angleRad) - right * sin(angleRad);
    double fieldOrientedRight = left * sin(angleRad) + right * cos(angleRad);

    drive->getModel()->tank(fieldOrientedLeft, fieldOrientedRight);

    pros::delay(20);
  }
}

/* Arcade Drive
void opcontrol() {
  while (true) {
    double forward = -master.getAnalog(ControllerAnalog::leftY);
    double rotate = master.getAnalog(ControllerAnalog::rightX);

    double theta = rotationSensor.get_position();

    double angleRad = theta * M_PI / 180.0;

    double fieldOrientedForward = forward * cos(angleRad) - rotate * sin(angleRad);
    double fieldOrientedRotate = forward * sin(angleRad) + rotate * cos(angleRad);

    double left = fieldOrientedForward + fieldOrientedRotate;
    double right = fieldOrientedForward - fieldOrientedRotate;

    drive->getModel()->tank(left, right);

    pros::delay(20);
  }
}
*/