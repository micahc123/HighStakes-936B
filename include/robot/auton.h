#ifndef AUTON_H
#define AUTON_H

#include "api.h"
#include "pros/rtos.hpp"
#include "lemlib/api.hpp"
#include "robot/pneumatics.h"
#include "robot/intake.h"

/**
 * @brief Enumeration of available autonomous routines.
 */
enum class AUTON_ROUTINE { RED_LEFT, RED_RIGHT, BLUE_LEFT, BLUE_RIGHT };

/**
 * @brief Initializes and runs the autonomous routine.
 */
void auton();

/**
 * @brief Sets the selected autonomous routine.
 * 
 * @param routine The autonomous routine to set.
 */
void setAutonRoutine(AUTON_ROUTINE routine);

/**
 * @brief Gets the currently selected autonomous routine.
 * 
 * @return The selected autonomous routine.
 */
AUTON_ROUTINE getAutonRoutine();

#endif // AUTON_H