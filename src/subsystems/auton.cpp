#include "robot/auton.h"
#include "globals.h"

//red_left
ASSET(red_left_part_1_txt);
ASSET(red_left_part_2_txt);
ASSET(red_left_part_3_txt);
ASSET(red_left_part_4_txt);
ASSET(red_left_part_5_txt);
ASSET(red_left_part_6_txt);
ASSET(red_left_part_7_txt);
ASSET(red_left_part_8_txt);
ASSET(red_left_part_9_txt);

//red right
ASSET(red_right_part_1_txt);
ASSET(red_right_part_2_txt);
ASSET(red_right_part_3_txt);
ASSET(red_right_part_4_txt);
ASSET(red_right_part_5_txt);
ASSET(red_right_part_6_txt);
ASSET(red_right_part_7_txt);


//blue_left
ASSET(blue_left_part_1_txt);
ASSET(blue_left_part_2_txt);
ASSET(blue_left_part_3_txt);
ASSET(blue_left_part_4_txt);
ASSET(blue_left_part_5_txt);
ASSET(blue_left_part_6_txt);
ASSET(blue_left_part_7_txt);
ASSET(blue_left_part_8_txt);
ASSET(blue_left_part_9_txt);

//blue right
ASSET(blue_right_part_1_txt);
ASSET(blue_right_part_2_txt);
ASSET(blue_right_part_3_txt);
ASSET(blue_right_part_4_txt);
ASSET(blue_right_part_5_txt);
ASSET(blue_right_part_6_txt);

//ASSET(blue_left_txt);
//ASSET(blue_right_txt);

namespace subsystems {

Auton::Auton(lemlib::Chassis* chassis) : chassis(chassis), selected_auton(AUTON_ROUTINE::NONE) {}

void Auton::run_red_left() {
    wall.set_target_position(360);
    uint32_t timeout = pros::millis() + 1000; 
    while (pros::millis() < timeout) {
        wall.update_position();
        pros::delay(10);
    }
    chassis->follow(red_left_part_1_txt, 10.0, 2000);
    clamp.clamp_stake();
    chassis->follow(red_left_part_2_txt, 10.0, 2000);
    intake.activate();
    chassis->follow(red_left_part_3_txt, 10.0, 2000);
    pros::delay(300);
    chassis->follow(red_left_part_4_txt, 10.0, 2000);
    pros::delay(300);

    chassis->follow(red_left_part_5_txt, 10.0, 2000);
    pros::delay(300);

    chassis->follow(red_left_part_6_txt, 10.0, 2000);
    pros::delay(300);

    chassis->follow(red_left_part_7_txt, 10.0, 2000);
    pros::delay(300);

    chassis->follow(red_left_part_8_txt, 10.0, 2000);
    pros::delay(500);
    intake.deactivate();
    pros::delay(300);
    chassis->follow(red_left_part_9_txt, 10.0, 2000);





    
}

void Auton::run_red_right() {
    intake.activate();
    chassis->follow(red_right_part_1_txt, 10.0, 2000);
    intake.deactivate();
    pros::delay(500);
    chassis->follow(red_right_part_2_txt, 10.0, 2000);
    doinker.activate();
    pros::delay(1000);
    chassis->follow(red_right_part_3_txt, 10.0, 2000);
    doinker.deactivate();
    chassis->follow(red_right_part_4_txt, 10.0, 2000);
    clamp.clamp_stake();
    pros::delay(300);
    intake.activate();
    pros::delay(300);
    clamp.declamp_stake();
    chassis->follow(red_right_part_5_txt, 10.0, 2000);
    clamp.clamp_stake();
    pros::delay(300);
    chassis->follow(red_right_part_6_txt, 10.0, 2000);
    wall.set_target_position(330);
    uint32_t timeout = pros::millis() + 1000; 
    while (pros::millis() < timeout) {
        wall.update_position();
        pros::delay(10);
    }
    chassis->follow(red_right_part_7_txt, 10.0, 2000);
    pros::delay(2000);
    intake.deactivate();

}

void Auton::run_blue_left() {
    wall.set_target_position(360);
    uint32_t timeout = pros::millis() + 1000; 
    while (pros::millis() < timeout) {
        wall.update_position();
        pros::delay(10);
    }
    chassis->follow(blue_left_part_1_txt, 10.0, 2000);
    clamp.clamp_stake();
    chassis->follow(blue_left_part_2_txt, 10.0, 2000);
    intake.activate();
    chassis->follow(blue_left_part_3_txt, 10.0, 2000);
    chassis->follow(blue_left_part_4_txt, 10.0, 2000);
    chassis->follow(blue_left_part_5_txt, 10.0, 2000);
    chassis->follow(blue_left_part_6_txt, 10.0, 2000);
    chassis->follow(blue_left_part_7_txt, 10.0, 2000);
    chassis->follow(blue_left_part_8_txt, 10.0, 2000);
    pros::delay(500);
    intake.deactivate();
    chassis->follow(blue_left_part_9_txt, 10.0, 2000);
}

void Auton::run_blue_right() {
    intake.activate();
    chassis->follow(blue_right_part_1_txt, 10.0, 2000);
    intake.deactivate();
    pros::delay(500);
    chassis->follow(blue_right_part_2_txt, 10.0, 2000);
    doinker.activate();
    pros::delay(1000);
    chassis->follow(blue_right_part_3_txt, 10.0, 2000);
    doinker.deactivate();
    chassis->follow(blue_right_part_4_txt, 10.0, 2000);
    clamp.clamp_stake();
    pros::delay(300);
    intake.activate();
    pros::delay(300);
    clamp.declamp_stake();
    chassis->follow(blue_right_part_5_txt, 10.0, 2000);
    clamp.clamp_stake();
    pros::delay(300);
    chassis->follow(blue_right_part_6_txt, 10.0, 2000);
    wall.set_target_position(330);
    uint32_t timeout = pros::millis() + 1000; 
    while (pros::millis() < timeout) {
        wall.update_position();
        pros::delay(10);
    }
    //chassis->follow(blue_right_part_7_txt, 10.0, 2000);
    pros::delay(2000);
    intake.deactivate();
}

void Auton::run_skills() {

    chassis->setPose(0, 0, 0);  
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
        case AUTON_ROUTINE::SKILLS:
            run_skills();
            break;
        case AUTON_ROUTINE::NONE:
            break;
    }
}

void Auton::set_selected_auton(AUTON_ROUTINE routine) {
    selected_auton = routine;
}

AUTON_ROUTINE Auton::get_selected_auton() {
    return selected_auton;
}

void Auton::test_lateral() {
    // Reset the robot's position
    chassis->setPose(0, 0, 0);
    // Move forward 48 inches (2 field tiles)
    chassis->moveToPoint(0, 48, 10000);
}

void Auton::test_angular() {
    // Reset the robot's position
    chassis->setPose(0, 0, 0);
    // Turn to face 90 degrees
    chassis->turnToHeading(90, 10000);
}

} // namespace subsystems