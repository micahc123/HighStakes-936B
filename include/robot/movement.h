#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "pros/motors.hpp"
#include "lemlib/api.hpp"
#include "pros/misc.hpp"
#include "pros/rtos.hpp"

namespace subsystems {

class Movement {
public:
    Movement(lemlib::Chassis* chassis);
    void drive(double leftY, double rightY);


private:
    lemlib::Chassis* chassis;
};

} 

#endif // MOVEMENT_H