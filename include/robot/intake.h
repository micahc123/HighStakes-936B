#ifndef INTAKE_H
#define INTAKE_H

#include "pros/optical.hpp"
#include "pros/motors.hpp"

namespace subsystems {

enum class DONUT_COLOR { NONE, RED, BLUE };

class Intake {
public:
    Intake(int port, int color_sensor_port);

    void move();
    void move_reverse();
    void run();
    void stop();
    bool is_active() const;
    void activate();
    void deactivate();
    void set_target_color(DONUT_COLOR color);
    pros::Optical& get_color_sensor() { return color_sensor; }
    void sort();

private:
    pros::Motor intake_motor;
    pros::Optical color_sensor;  
    bool active;
    DONUT_COLOR target_color;
};

}

#endif // INTAKE_H