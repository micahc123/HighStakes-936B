#include "robot/intake.h"
#include "globals.h"

namespace subsystems {

Intake::Intake(int port, int color_sensor_port)
    : intake_motor(port), 
      color_sensor(color_sensor_port),
      active(false),
      target_color(DONUT_COLOR::NONE) {}

void Intake::move() {
    intake_motor.move_voltage(-10000);
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

void Intake::run() {
    if (master.get_digital_new_press(DIGITAL_L1)) {
        active = !active;
        if (active) {
            move();
            pros::lcd::print(1, "Intake: Active");
        } else {
            stop();
            pros::lcd::print(1, "Intake: Inactive");
        }
    }
    
    // New color detection logic
    if (active) {
        int hue = color_sensor.get_hue();
        static bool color_detected = false;
        static uint32_t detection_time = 0;
        static uint32_t stop_time = 0;
        
        pros::lcd::print(2, "Hue: %d", hue);
        
        if (hue > 200 && hue < 240) {
            if (!color_detected) {
                color_detected = true;
                detection_time = pros::millis();
                stop_time = detection_time + 100;
                pros::lcd::print(3, "Blue detected! Waiting to stop");
            }
            
            if (pros::millis() >= stop_time && color_detected) {
                stop();
                pros::lcd::print(3, "Stopping after delay");
            }
            
                        if (pros::millis() - detection_time > 120) {
                move();
                color_detected = false;
                pros::lcd::print(3, "Resuming movement");
            }
        } else {
            if (!color_detected) {
                move();  
                pros::lcd::print(3, "No color detected - Moving");
            }
        }
    }
}

/* Old color sorting code updated with similar timing logic
void Intake::run() {
    if (master.get_digital_new_press(DIGITAL_L1)) {
        active = !active;
        if (active) {
            move();
            pros::lcd::print(1, "Intake: Active");
        } else {
            stop();
            pros::lcd::print(1, "Intake: Inactive");
        }
    }
    
    if (active && target_color != DONUT_COLOR::NONE) {
        int hue = color_sensor.get_hue();
        static bool color_detected = false;
        static uint32_t detection_time = 0;
        static uint32_t stop_time = 0;
        
        pros::lcd::print(2, "Hue: %d Target: %d", hue, static_cast<int>(target_color));
        
        bool is_target_color = (target_color == DONUT_COLOR::RED && hue > 330) || 
                              (target_color == DONUT_COLOR::BLUE && hue > 200 && hue < 240);
        
        if (is_target_color) {
            if (!color_detected) {
                color_detected = true;
                detection_time = pros::millis();
                stop_time = detection_time + 100;
                pros::lcd::print(3, "Target color detected! Waiting to stop");
            }
            
            // Stop after initial delay
            if (pros::millis() >= stop_time && color_detected) {
                stop();
                pros::lcd::print(3, "Stopping after delay");
            }
            
            // Start moving again after stop delay
            if (pros::millis() - detection_time > 120) {
                move();
                color_detected = false;
                pros::lcd::print(3, "Resuming movement");
            }
        } else {
            if (!color_detected) {
                move();
                pros::lcd::print(3, "No target color - Moving");
            }
        }
    }
}
*/

}