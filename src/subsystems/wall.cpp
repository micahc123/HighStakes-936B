#include "robot/wall.h"
#include "globals.h"

namespace subsystems {

Wall::Wall(int left_port, int right_port) 
    : left_wall_motor(left_port, pros::E_MOTOR_GEAR_GREEN),
      right_wall_motor(right_port, pros::E_MOTOR_GEAR_GREEN),
      target_position(START_POS) {
    left_wall_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    right_wall_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    left_wall_motor.set_reversed(true);
    
    left_wall_motor.tare_position();
    right_wall_motor.tare_position();
    
    left_wall_motor.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
    right_wall_motor.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);

    pros::Task position_update_task([this] {
        while (true) {
            update_position();
            pros::delay(10);
        }
    });
}

void Wall::set_target_position(int position) {
    target_position = position * GEAR_RATIO;
}

void Wall::update_position() {
    double current_pos = ((left_wall_motor.get_position() + right_wall_motor.get_position()) / 2.0) * GEAR_RATIO;
    double error = target_position - current_pos;
    
    if (std::abs(error) > 5) {
        double kp = 0.2;
        double velocity = std::clamp(kp * error, -100.0, 100.0);  
        
        left_wall_motor.move(velocity);
        right_wall_motor.move(velocity);
    } else {
        left_wall_motor.move(0);
        right_wall_motor.move(0);
    }
}

void Wall::run() {
    if (master.get_digital_new_press(DIGITAL_R1)) {
        set_target_position(SCORE_POS);
    }
    if (master.get_digital_new_press(DIGITAL_X)) {
        set_target_position(STOW_POS);
    }
    if (master.get_digital_new_press(DIGITAL_R2)) {
        set_target_position(START_POS);
    }
}

}
