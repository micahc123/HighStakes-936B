#ifndef INTAKE_H
#define INTAKE_H

#include "pros/motors.hpp"  // Added include for pros::Motor

namespace subsystems {

class Intake {
public:
    Intake(int port);
    void activate();
    void deactivate();
    void set_voltage(int voltage);
    bool is_active() const;

private:
    pros::Motor intake_motor;
    bool active;
};

} // namespace subsystems

#endif // INTAKE_H