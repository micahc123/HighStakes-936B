#include "robot/intake.h"
#include "globals.h"

namespace subsystems {

Intake::Intake(int port, int color_sensor_port)
    : intake_motor(port), 
      color_sensor(color_sensor_port),
      active(false),
      target_color(DONUT_COLOR::NONE) {}

void Intake::move_forward() {
    intake_motor.move_voltage(-12000);
}

void Intake::move_backward() {
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
    move_forward();
}

void Intake::deactivate() {
    active = false;
    stop();
}

void Intake::set_target_color(DONUT_COLOR color) {
    target_color = color;
}


void Intake::run() {
    if (master.get_digital(DIGITAL_L2)) {
        move_forward();
        active = true;
    } else if (master.get_digital(DIGITAL_L1)) {
        move_backward();
        active = true;
    } else if (master.get_digital(DIGITAL_DOWN)) {
        active = true;
        move_forward();
        
        while (true) {
            int hue = color_sensor.get_hue();
            
            if ((hue > 210) || (hue < 30)) {
                pros::delay(15);
                stop();
                break;
            }
            pros::delay(10);
        }
    } else {
        deactivate();
    }
    
    if (active && target_color != DONUT_COLOR::NONE) {
        int hue = color_sensor.get_hue();
        
        if ((target_color == DONUT_COLOR::RED && hue > 210) ||  
            (target_color == DONUT_COLOR::BLUE && hue < 30)) {
            pros::delay(15);
            stop();
        }
    }
}

}