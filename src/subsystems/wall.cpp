#include "robot/wall.h"
#include "globals.h"

namespace subsystems {

Wall::Wall(int motor_port)
    : wall_motor(motor_port) {}

void Wall::move_forward() {
    wall_motor.move_voltage(6000);
}

void Wall::move_backward() {
    wall_motor.move_voltage(-6000);
}

void Wall::stop() {
    wall_motor.move_voltage(0);
}

bool Wall::is_active() const {
    return active;
}

void Wall::activate() {
    active = true;
    move_forward();
}

void Wall::deactivate() {
    active = false;
    stop();
}

} // namespace subsystems