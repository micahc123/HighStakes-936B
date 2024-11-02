#ifndef AUTON_H
#define AUTON_H

#include "api.h"
#include "lemlib/api.hpp"
#include "robot/auton_selector.h"

namespace subsystems {

class Auton {
public:
    Auton(lemlib::Chassis* chassis);
    void run_auton(AUTON_ROUTINE routine);

private:
    void run_red_left();
    void run_red_right();
    void run_blue_left();
    void run_blue_right();

    lemlib::Chassis* chassis;
};

} // namespace subsystems

#endif // AUTON_H