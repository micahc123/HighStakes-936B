#include "robot/clamp.h"
#include "globals.h"

namespace subsystems {

Clamp::Clamp(char port)
    : piston(port), piston_toggle(false) {}

void Clamp::toggle() {
    piston_toggle = !piston_toggle;
    piston.set_value(piston_toggle);
}

void Clamp::clamp_stake() {
    piston_toggle = true;
    piston.set_value(true);
}

void Clamp::declamp_stake() {
    piston_toggle = false;
    piston.set_value(false);
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