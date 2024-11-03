#include "robot/movement.h"
#include "globals.h"
#include "pros/motors.hpp"
#include "pros/misc.hpp"

namespace subsystems {

Movement::Movement(lemlib::Chassis* chassis)
    : chassis(chassis) {}

void Movement::tank_drive(double leftY, double rightY) {
    chassis->tank(leftY, rightY);
}

} 