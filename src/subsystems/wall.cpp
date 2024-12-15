#include "robot/wall.h"
#include "globals.h"

namespace subsystems {

Wall::Wall(int motor_port, int rotation_port)
    : wall_motor(motor_port), rotation_sensor(rotation_port) {
    move_to_start();
}

void Wall::move_to_position(double target) {
    double current = rotation_sensor.get_position();
    double error = target - current;
    //pid for smoother movement
    if (std::abs(error) > POSITION_THRESHOLD) {
        double kP = 30.0; 
        int voltage = std::clamp(static_cast<int>(error * kP), -MOTOR_VOLTAGE, MOTOR_VOLTAGE);
        wall_motor.move_voltage(voltage);
    } else {
        stop();
    }
}

bool Wall::is_at_position(double target) {
    return std::abs(rotation_sensor.get_position() - target) <= POSITION_THRESHOLD;
}

void Wall::move_to_start() {
    move_to_position(START_POSITION);
}

void Wall::move_to_bottom() {
    move_to_position(BOTTOM_POSITION);
}

void Wall::move_to_score() {
    move_to_position(SCORE_POSITION);
}

void Wall::stop() {
    wall_motor.move_voltage(0);
}

void Wall::run() {
    if (master.get_digital(DIGITAL_R1) && master.get_digital(DIGITAL_R2)) {
        move_to_bottom();
    } else if (master.get_digital(DIGITAL_R2)) {
        move_to_start();
    } else if (master.get_digital(DIGITAL_R1)) {
        move_to_score();
    }
}

}