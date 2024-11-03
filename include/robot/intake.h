#ifndef INTAKE_H
#define INTAKE_H

#include "pros/adi.hpp"
#include "pros/optical.hpp"

namespace subsystems {

enum class DONUT_COLOR { NONE, RED, BLUE };

class Intake {
public:
    Intake(int port, int color_sensor_port, int distance_sensor_port);
    void move_forward();
    void move_backward();
    void run();
    void stop();
    bool is_active() const;
    void activate();
    void deactivate();
    void set_target_color(DONUT_COLOR color);

private:
    pros::Motor intake_motor;
    pros::Optical color_sensor;
    pros::Distance distance_sensor;
    bool active;
    DONUT_COLOR target_color;
};

}

#endif // INTAKE_H