#include "robot/pneumatics.h"
#include "globals.h"
namespace subsystems {

Pneumatics::Pneumatics(char port)
    : piston(port), piston_toggle(false) {}

void Pneumatics::toggle() {
    piston_toggle = !piston_toggle;
    piston.set_value(piston_toggle ? 1 : 0);
}

void Pneumatics::clamp_stake() {
    piston_toggle = true;
    piston.set_value(1);
    pros::delay(500); // Adjust delay as needed for piston activation
}

void Pneumatics::declamp_stake() {
    piston_toggle = false;
    piston.set_value(0);
    pros::delay(500); // Adjust delay as needed for piston deactivation
}

bool Pneumatics::get_state() const {
    return piston_toggle;
}
void Pneumatics::run() {
    if (master.get_digital_new_press(DIGITAL_L1)) {
        toggle();
    }
}

} // namespace subsystems