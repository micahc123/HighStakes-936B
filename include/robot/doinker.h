#ifndef DOINKER_H
#define DOINKER_H

#include "pros/adi.hpp"
#include "pros/rtos.hpp"

namespace subsystems {

class Doinker {
public:
    Doinker(char port);
    void toggle();
    void run();
    void activate();
    void deactivate();
    bool get_state() const;

private:
    pros::ADIDigitalOut piston;
    bool piston_toggle;
};

}

#endif // DOINKER_H