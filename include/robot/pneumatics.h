#ifndef PNEUMATICS_H
#define PNEUMATICS_H

/**
 * @brief Toggles the piston state based on controller input.
 */
void pneumatics();

/**
 * @brief Clamps the stake by activating the piston.
 */
void clampStake();

/**
 * @brief Declamps the stake by deactivating the piston.
 */
void declampStake();

#endif // PNEUMATICS_H