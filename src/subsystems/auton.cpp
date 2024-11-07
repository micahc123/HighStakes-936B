#include "robot/auton.h"
#include "globals.h"

// assets from path.jerryio
ASSET(red_left_part_1_text);
ASSET(red_left_part_2_text);
ASSET(red_left_part_3_text);
ASSET(red_left_part_4_text);
//ASSET(red_right_txt);
//ASSET(blue_left_txt);
//ASSET(blue_right_txt);

namespace subsystems {

Auton::Auton(lemlib::Chassis* chassis) : chassis(chassis), selected_auton(AUTON_ROUTINE::RED_LEFT) {}

void Auton::run_red_left() {
    chassis->follow(red_left_part_1_text, 2.0, 10000, true, false);
    clamp.clamp_stake();
    pros::delay(1000);
    chassis->follow(red_left_part_2_text, 2.0, 10000, true, false);
    intake.activate();
    pros::delay(1000);
    chassis->follow(red_left_part_3_text, 2.0, 10000, true, false);
    pros::delay(1000);
    chassis->follow(red_left_part_4_text, 2.0, 10000, true, false);
    intake.deactivate();
    clamp.declamp_stake();
}

void Auton::run_red_right() {
    //chassis->follow(red_right_txt, 2.0, 10000, true, false);
}

void Auton::run_blue_left() {
    //chassis->follow(blue_left_txt, 2.0, 10000, true, false);
}

void Auton::run_blue_right() {
    //chassis->follow(blue_right_txt, 2.0, 10000, true, false);
}

void Auton::run_auton(AUTON_ROUTINE routine) {
    switch (routine) {
        case AUTON_ROUTINE::RED_LEFT:
            run_red_left();
            break;
        case AUTON_ROUTINE::RED_RIGHT:
            run_red_right();
            break;
        case AUTON_ROUTINE::BLUE_LEFT:
            run_blue_left();
            break;
        case AUTON_ROUTINE::BLUE_RIGHT:
            run_blue_right();
            break;
    }
}

void Auton::set_selected_auton(AUTON_ROUTINE routine) {
    selected_auton = routine;
}
AUTON_ROUTINE Auton::get_selected_auton() {
    return selected_auton;
}

} // namespace subsystems