#include "robot/clamp.h"
#include "globals.h"

namespace subsystems {

Clamp::Clamp(char port_left, char port_right)
    : piston_left(port_left), piston_right(port_right), piston_toggle(false) {}

void Clamp::toggle() {
    piston_toggle = !piston_toggle;
    piston_left.set_value(piston_toggle ? 1 : 0);
    piston_right.set_value(piston_toggle ? 1 : 0);
}

void Clamp::clamp_stake() {
    piston_toggle = true;
    piston_left.set_value(1);
    piston_right.set_value(1);
    pros::delay(500);
}

void Clamp::declamp_stake() {
    piston_toggle = false;
    piston_left.set_value(0);
    piston_right.set_value(0);
    pros::delay(500); 
}

bool Clamp::get_state() const {
    return piston_toggle;
}

void Clamp::run() {
    if (master.get_digital_new_press(DIGITAL_A)) {
        toggle();
    }
}

}