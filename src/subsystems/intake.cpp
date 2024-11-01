#include "robot/intake.h"
#include "setup.h"
#include "globals.h"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"

// Assuming intakeMotor is defined in globals.h or setup.h
extern pros::Motor intakeMotor;

/**
 * @brief Controls the intake based on controller input.
 */
void intake() {
    bool isIntakeForwardButtonPressed = master.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    bool isIntakeBackwardButtonPressed = master.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
    
    if (isIntakeForwardButtonPressed) {
        intakeMotor.move_voltage(12000);
    } else if (isIntakeBackwardButtonPressed) {
        intakeMotor.move_voltage(-12000);
    } else {
        intakeMotor.move_voltage(0);
    }
}

/**
 * @brief Activates the intake motor to collect game elements.
 */
void activateIntake() {
    intakeMotor.move_voltage(12000); // Adjust voltage as needed
}

/**
 * @brief Deactivates the intake motor.
 */
void deactivateIntake() {
    intakeMotor.move_voltage(0);
}

/**
 * @brief Sets the intake motor speed.
 * 
 * @param voltage The voltage to set for the intake motor.
 */
void setIntakeVoltage(int voltage) {
    intakeMotor.move_voltage(voltage);
}