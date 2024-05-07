#include "main.h"


auto leftMotors = MotorGroup({11, 12}); 
auto rightMotors = MotorGroup({1, 2});

auto drive = ChassisControllerBuilder()
    .withMotors(leftMotors, rightMotors) 
    .withDimensions(AbstractMotor::gearset::blue, {{4_in, 10_in}, imev5BlueTPR})
    .build();
    
Controller master;

void opcontrol() {
  while (true) {
    
    double left = -master.getAnalog(ControllerAnalog::leftY);
    double right = master.getAnalog(ControllerAnalog::rightY);

    if (master.getDigital(ControllerDigital::R1)) {
      left = 100;
      right = 100;
    }
    if (master.getDigital(ControllerDigital::L1) && master.getDigital(ControllerDigital::R1)) {
      drive->turnAngle(180_deg);
    }

    drive->getModel()->tank(left, right);

    pros::delay(20);
  }
}
