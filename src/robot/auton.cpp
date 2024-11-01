#include "robot/auton.h"
#include "setup.h"
#include "globals.h"
#include "robot/pneumatics.h"
#include "robot/intake.h"
#include "lemlib/api.hpp"

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

/**
 * @brief Sets the selected autonomous routine.
 * 
 * @param routine The autonomous routine to set.
 */
void setAutonRoutine(AUTON_ROUTINE routine) {
    selectedAuton = routine;
}

/**
 * @brief Gets the currently selected autonomous routine.
 * 
 * @return The selected autonomous routine.
 */
AUTON_ROUTINE getAutonRoutine() {
    return selectedAuton;
}

/**
 * @brief Executes the selected autonomous routine.
 */
void auton() {
    switch (selectedAuton) {
        case AUTON_ROUTINE::RED_LEFT:
            {
                
                // Step 3: Keep Intake Active While Following Path
                chassis.follow(red_left_part1_txt, 2.0, 10000, true, false);
                clampStake();
                pros::delay(1000);
                chassis.follow(red_left_part2_txt, 2.0, 10000, true, false);
                activateIntake();
                pros::delay(1000);
                chassis.follow(red_left_part3_txt, 2.0, 10000, true, false);
                pros::delay(1000);
                chassis.follow(red_left_part4_txt, 2.0, 10000, true, false);
                deactivateIntake();
                declampStake();
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
            // Default autonomous routine or do nothing
            break;
    }

    // Additional autonomous actions can be added here if needed
}