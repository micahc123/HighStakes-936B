#ifndef CLAMP_H
#define CLAMP_H

#include "pros/adi.hpp"
#include "pros/rtos.hpp"

namespace subsystems {

class Clamp {
public:
    Clamp(char port_left, char port_right);
    void toggle();
    void run();
    void clamp_stake();
    void declamp_stake();
    bool get_state() const;

private:
    pros::ADIDigitalOut piston_left;
    pros::ADIDigitalOut piston_right;
    bool piston_toggle;
};

}

#endif // CLAMP_H