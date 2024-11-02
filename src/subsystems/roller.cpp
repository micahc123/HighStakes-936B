#include "robot/roller.h"
#include "globals.h"
namespace subsystems {

Roller::Roller(int port)
    : roller_motor(port), active(false) {}

void Roller::activate() {
    active = true;
    roller_motor.move_voltage(12000);
}

void Roller::deactivate() {
    active = false;
    roller_motor.move_voltage(0);
}

void Roller::set_voltage(int voltage) {
    roller_motor.move_voltage(voltage);
    active = (voltage != 0);
}

bool Roller::is_active() const {
    return active;
}
void Roller::run() {
    if (master.get_digital_new_press(DIGITAL_R1)) {
        if (!is_active()) {
            set_voltage(12000);  
        } else {
            deactivate();       
        }
    }
}
} 