#ifndef WALL_H
#define WALL_H

#include "pros/motors.hpp"

namespace subsystems {

class Wall {
public:
    Wall(int left_port, int right_port);
    
    void set_target_position(int position);
    void update_position();
    void run();

private:
    pros::Motor left_wall_motor;
    pros::Motor right_wall_motor;
    
    double target_position;
    
    static constexpr int START_POS = 40;
    static constexpr int SCORE_POS = 340;  
    static constexpr int STOW_POS = 0;
    static constexpr int DESCORE_POS = 550;  
    static constexpr double GEAR_RATIO = 3.0; 
    
};

}

#endif // WALL_H