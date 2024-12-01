#ifndef WALL_H
#define WALL_H
#include "pros/motors.hpp"
#include "pros/rotation.hpp"

namespace subsystems {

class Wall {
public:
    Wall(int motor_port, int rotation_port);
    
    void move_to_start();    
    void move_to_bottom();  
    void move_to_score();   
    
    void run();
    void stop();
    
private:
    static constexpr int START_POSITION = 0;    
    static constexpr int BOTTOM_POSITION = 900;  
    static constexpr int SCORE_POSITION = 450;   
    
    static constexpr int POSITION_THRESHOLD = 5;  
    static constexpr int MOTOR_VOLTAGE = 12000; 
    
    void move_to_position(double target);
    bool is_at_position(double target);
    
    pros::Motor wall_motor;
    pros::Rotation rotation_sensor;
};
}

#endif // WALL_H