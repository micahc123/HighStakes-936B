#ifndef WALL_H
#define WALL_H

#include "pros/motors.hpp"

namespace subsystems {

class Wall {
public:
    Wall(int left_port, int right_port);
    void run();

    // Target positions in encoder ticks
    static constexpr int START_POS = 0;      // Starting/default position
    static constexpr int DOWN_POS = -200;    // Down position (adjust this)
    static constexpr int SCORE_POS = 400;    // Score position (adjust this)
    
    // PID constants - tune these
    static constexpr double kP = 0.5;  // Increase to make movement more aggressive
    static constexpr double kI = 0.001; // Increase to reduce steady-state error
    static constexpr double kD = 0.1;   // Increase to reduce oscillation
    
    // Tolerance for position
    static constexpr int POSITION_TOLERANCE = 5;

private:
    pros::Motor left_wall_motor;
    pros::Motor right_wall_motor;
    int target_position;
    double integral;
    double prev_error;
    
    void move_to_position(int position);
    double calculate_pid(double error);
    void reset_pid();
};

}

#endif // WALL_H