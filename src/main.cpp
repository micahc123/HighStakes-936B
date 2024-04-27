#include "main.h"

using namespace okapi;

auto drive = ChassisControllerBuilder()
    .withMotors({1, 3}, {2, 4}) 
    .withDimensions(AbstractMotor::gearset::blue, {{4_in, 10_in}, imev5BlueTPR})
    .build();

Controller master;

pros::Rotation rotationSensor(5);

void opcontrol() {
  while (true) {
    double forward = -master.getAnalog(ControllerAnalog::leftY);
    double strafe = master.getAnalog(ControllerAnalog::leftX);
    double rotate = master.getAnalog(ControllerAnalog::rightX);

    double theta = rotationSensor.get_position();

    double angleRad = theta * M_PI / 180.0;

    double fieldOrientedForward = forward * cos(angleRad) - strafe * sin(angleRad);
    double fieldOrientedStrafe = forward * sin(angleRad) + strafe * cos(angleRad);

    drive->getModel()->arcade(fieldOrientedForward, fieldOrientedStrafe, rotate);

    pros::delay(20);
  }
}