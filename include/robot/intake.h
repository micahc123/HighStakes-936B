#ifndef INTAKE_H
#define INTAKE_H

/**
 * @brief Controls the intake based on controller input.
 */
void intake();

/**
 * @brief Activates the intake motor to collect game elements.
 */
void activateIntake();

/**
 * @brief Deactivates the intake motor.
 */
void deactivateIntake();

/**
 * @brief Sets the intake motor speed.
 * 
 * @param voltage The voltage to set for the intake motor.
 */
void setIntakeVoltage(int voltage);

#endif // INTAKE_H