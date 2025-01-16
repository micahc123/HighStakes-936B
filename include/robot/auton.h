#ifndef AUTON_H
#define AUTON_H

#include "lemlib/api.hpp"

namespace subsystems {

// Values match the button map indices:
// Front (0) = RED_LEFT/BLUE_LEFT (1/-1)
// Back (1) = RED_RIGHT/BLUE_RIGHT (2/-2)
// Do Nothing (2) = NONE (3/-3)
enum class AUTON_ROUTINE { 
    SKILLS = 0,
    RED_LEFT = 1, BLUE_LEFT = -1,
    RED_RIGHT = 2, BLUE_RIGHT = -2,
    NONE = 3
};

class Auton {
public:
    Auton(lemlib::Chassis* chassis);
    AUTON_ROUTINE get_selected_auton();
    void run_auton(AUTON_ROUTINE routine);
    void set_selected_auton(AUTON_ROUTINE routine);

private:
    lemlib::Chassis* chassis;
    AUTON_ROUTINE selected_auton;
    void run_red_left();
    void run_red_right();
    void run_blue_left();
    void run_blue_right();
    void run_skills();
};

} // namespace subsystems

#endif // AUTON_H