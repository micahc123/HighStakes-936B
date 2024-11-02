#include "robot/auton.h"
#include "globals.h"

// Define assets for autonomous paths
ASSET(red_left_part1_txt);
ASSET(red_left_part2_txt);
ASSET(red_left_part3_txt);
ASSET(red_left_part4_txt);
ASSET(red_right_txt);
ASSET(blue_left_txt);
ASSET(blue_right_txt);

/**
 * @brief The currently selected autonomous routine.
 */
static AUTON_ROUTINE selectedAuton = AUTON_ROUTINE::RED_LEFT;

void setAutonRoutine(AUTON_ROUTINE routine) {
    selectedAuton = routine;
}

AUTON_ROUTINE getAutonRoutine() {
    return selectedAuton;
}

void auton() {
    switch (selectedAuton) {
        case AUTON_ROUTINE::RED_LEFT:
            {
                // Step 3: Keep Intake Active While Following Path
                chassis.follow(red_left_part1_txt, 2.0, 10000, true, false);
                pneumatics.clamp_stake();
                pros::delay(1000);
                chassis.follow(red_left_part2_txt, 2.0, 10000, true, false);
                intake.activate();
                pros::delay(1000);
                chassis.follow(red_left_part3_txt, 2.0, 10000, true, false);
                pros::delay(1000);
                chassis.follow(red_left_part4_txt, 2.0, 10000, true, false);
                intake.deactivate();
                pneumatics.declamp_stake();
                break;
            }
        case AUTON_ROUTINE::RED_RIGHT:
            {
                chassis.follow(red_right_txt, 2.0, 10000, true, false);
                break;
            }
        case AUTON_ROUTINE::BLUE_LEFT:
            {
                chassis.follow(blue_left_txt, 2.0, 10000, true, false);
                break;
            }
        case AUTON_ROUTINE::BLUE_RIGHT:
            {
                chassis.follow(blue_right_txt, 2.0, 10000, true, false);
                break;
            }
        default:
            break;
    }
}