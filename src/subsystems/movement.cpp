#include "robot/movement.h"
#include "setup.h"

void movement() {
    // Driver control
    double leftY = -master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    double rightY = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    chassis.tank(leftY, rightY);
}