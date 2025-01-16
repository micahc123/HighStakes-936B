#include "robot/wall.h"
#include "globals.h"

namespace subsystems {

Wall::Wall(int left_port, int right_port) 
    : left_wall_motor(left_port), right_wall_motor(right_port),
      target_position(START_POS), integral(0), prev_error(0) {
    left_wall_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    right_wall_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    
    left_wall_motor.tare_position();
    right_wall_motor.tare_position();
}

double Wall::calculate_pid(double error) {
    integral += error;
    double derivative = error - prev_error;
    prev_error = error;
    
    if (integral > 1000) integral = 1000;
    if (integral < -1000) integral = -1000;
    
    return (error * kP) + (integral * kI) + (derivative * kD);
}

void Wall::reset_pid() {
    integral = 0;
    prev_error = 0;
}

void Wall::move_to_position(int position) {
    target_position = position;
    
    double current_pos = (left_wall_motor.get_position() + right_wall_motor.get_position()) / 2.0;
    
    double error = target_position - current_pos;
    
    if (abs(error) < POSITION_TOLERANCE) {
        left_wall_motor.move_voltage(0);
        right_wall_motor.move_voltage(0);
        reset_pid();
        return;
    }
    
    double output = calculate_pid(error);
    
    int voltage = output * 12000;
    if (voltage > 12000) voltage = 12000;
    if (voltage < -12000) voltage = -12000;
    
    left_wall_motor.move_voltage(voltage);
    right_wall_motor.move_voltage(voltage);
}

void Wall::run() {
    if (master.get_digital_new_press(DIGITAL_R1)) {
        move_to_position(SCORE_POS);
    }
    else if (master.get_digital_new_press(DIGITAL_X)) {
        move_to_position(DOWN_POS);
    }
    else if (master.get_digital(DIGITAL_R2)) {
        move_to_position(START_POS);
    }
    
    move_to_position(target_position);
}

}