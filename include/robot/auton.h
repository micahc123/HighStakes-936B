#ifndef AUTON_H
#define AUTON_H

#include "lemlib/api.hpp"

namespace subsystems {

enum class AUTON_ROUTINE { NONE, RED_LEFT, RED_RIGHT, BLUE_LEFT, BLUE_RIGHT, SKILLS };


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