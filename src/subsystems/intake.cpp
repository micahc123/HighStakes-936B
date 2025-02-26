#include "robot/intake.h"
#include "globals.h"

namespace subsystems {

Intake::Intake(int port, int color_sensor_port)
    : intake_motor(port), 
      color_sensor(color_sensor_port),
      active(false),
      target_color(DONUT_COLOR::NONE) {
    pros::Task color_sort_task([this] {
        while (true) {
            sort();
            pros::delay(10);
        }
    });
}

void Intake::move() {
    intake_motor.move_voltage(-12000);
}

void Intake::move_reverse() {
    intake_motor.move_voltage(12000);
}

void Intake::stop() {
    intake_motor.move_voltage(0);
}

bool Intake::is_active() const {
    return active;
}

void Intake::activate() {
    active = true;
    move();
}

void Intake::deactivate() {
    active = false;
    stop();
}

void Intake::set_target_color(DONUT_COLOR color) {
    target_color = color;
}

void Intake::sort() {
    if (active && target_color != DONUT_COLOR::NONE) {
        int hue = color_sensor.get_hue();
        static bool color_detected = false;
        static uint32_t detection_time = 0;
        static uint32_t stop_time = 0;
        
        bool is_target_color = (target_color == DONUT_COLOR::RED && hue > 330) || 
                              (target_color == DONUT_COLOR::BLUE && hue > 200 && hue < 240);
        
        if (is_target_color) {
            if (!color_detected) {
                color_detected = true;
                detection_time = pros::millis();
                stop_time = detection_time + 100;
            }
            
            if (pros::millis() >= stop_time && color_detected) {
                stop();
            }
            
            if (pros::millis() - detection_time > 120) {
                move();
                color_detected = false;
            }
        } else {
            if (!color_detected) {
                move();
            }
        }
    }
}

void Intake::run() {
    // Toggle intake on/off when L1 is newly pressed.
    if (master.get_digital_new_press(DIGITAL_L1)) {
        active = !active;
    }
    
    // If L2 is pressed, run the motor in reverse.
    if (master.get_digital(DIGITAL_L2)) {
        move_reverse();
    }
    // Otherwise, if intake is active, run it forward.
    else if (active) {
        move();
    }
    // If not active, stop the motor.
    else {
        stop();
    }
}

}