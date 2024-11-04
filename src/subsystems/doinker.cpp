#include "robot/doinker.h"
#include "globals.h"

namespace subsystems {

Doinker::Doinker(char port)
    : piston(port), piston_toggle(false) {}

void Doinker::toggle() {
    piston_toggle = !piston_toggle;
    piston.set_value(piston_toggle ? 1 : 0);
}

void Doinker::activate() {
    piston_toggle = true;
    piston.set_value(1);
}

void Doinker::deactivate() {
    piston_toggle = false;
    piston.set_value(0);
}

bool Doinker::get_state() const {
    return piston_toggle;
}

void Doinker::run() {
    if (master.get_digital_new_press(DIGITAL_B)) {
        toggle();
    }
}

}