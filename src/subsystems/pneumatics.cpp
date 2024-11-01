#include "robot/pneumatics.h"
#include "setup.h"
#include "globals.h"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"

// Assuming piston is defined in globals.h or setup.h
extern pros::ADIDigitalOut piston;
extern bool pistonToggle;

/**
 * @brief Toggles the piston state based on controller input.
 */
void pneumatics() {
    bool isPistonButtonPressed = master.get_digital(pros::E_CONTROLLER_DIGITAL_A);
    
    if (isPistonButtonPressed) {
        pistonToggle = !pistonToggle;
        while (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
            pros::delay(1);
        }
    }
    
    piston.set_value(pistonToggle ? 1 : 0);
}

/**
 * @brief Clamps the stake by activating the piston.
 */
void clampStake() {
    pistonToggle = true;
    piston.set_value(1);
    pros::delay(500); // Adjust delay as needed for piston activation
}

/**
 * @brief Declamps the stake by deactivating the piston.
 */
void declampStake() {
    pistonToggle = false;
    piston.set_value(0);
    pros::delay(500); // Adjust delay as needed for piston deactivation
}