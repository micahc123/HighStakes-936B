#include "robot/movement.h"
#include "globals.h"
#include "pros/motors.hpp"
#include "pros/misc.hpp"

namespace subsystems {

Movement::Movement(lemlib::Chassis* chassis)
    : chassis(chassis) {    }


void Movement::drive(double leftY, double rightY) {
    chassis->arcade(-leftY, rightY);
}

} 