#ifndef PNEUMATICS_H
#define PNEUMATICS_H

#include "pros/adi.hpp"

namespace subsystems {

class Pneumatics {
public:
    Pneumatics(char port);
    void toggle();
    void clamp_stake();
    void declamp_stake();
    bool get_state() const;

private:
    pros::ADIDigitalOut piston;
    bool piston_toggle;
};

} // namespace subsystems

#endif // PNEUMATICS_H