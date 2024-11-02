#include "robot/intake.h"

namespace subsystems {

Intake::Intake(int port)
    : intake_motor(port), active(false) {}

void Intake::activate() {
    active = true;
    intake_motor.move_voltage(12000);
}

void Intake::deactivate() {
    active = false;
    intake_motor.move_voltage(0);
}

void Intake::set_voltage(int voltage) {
    intake_motor.move_voltage(voltage);
    active = (voltage != 0);
}

bool Intake::is_active() const {
    return active;
}

} // namespace subsystems