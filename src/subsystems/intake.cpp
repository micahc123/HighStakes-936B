#include "robot/intake.h"
#include "globals.h"

namespace subsystems {

Intake::Intake(int port, int color_sensor_port, int distance_sensor_port)
    : intake_motor(port), 
      color_sensor(color_sensor_port),
      distance_sensor(distance_sensor_port),
      active(false),
      target_color(DONUT_COLOR::NONE) {}

void Intake::move_forward() {
    intake_motor.move_voltage(12000);
}

void Intake::move_backward() {
    intake_motor.move_voltage(-12000);
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
    } else {
        deactivate();
    }

    if (active) {
        int distance = distance_sensor.get();
        if (distance < 50) {
            stop();
            pros::delay(100);
            move_forward();
        }

        if (target_color != DONUT_COLOR::NONE) {
            int hue = color_sensor.get_hue();
            if ((target_color == DONUT_COLOR::RED && hue < 30) || 
                (target_color == DONUT_COLOR::BLUE && hue > 210)) {
                stop();
                pros::delay(100);
                move_forward();
            }
        }
    }
}

} 