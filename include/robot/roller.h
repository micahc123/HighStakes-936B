#ifndef ROLLER_H
#define ROLLER_H

#include "pros/motors.hpp"

namespace subsystems {

class Roller {
public:
    Roller(int port);
    void activate();
    void deactivate();
    void run();

    void set_voltage(int voltage);
    bool is_active() const;

private:
    pros::Motor roller_motor;
    bool active;
};

} // namespace subsystems

#endif // ROLLER_H