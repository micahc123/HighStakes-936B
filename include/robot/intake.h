#ifndef INTAKE_H
#define INTAKE_H

#include "pros/optical.hpp"
#include "pros/motors.hpp"

namespace subsystems {

enum class DONUT_COLOR { NONE, RED, BLUE };

class Intake {
public:
    Intake(int port, int top_color_sensor_port);
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
    pros::Optical top_color_sensor;  // Only keeping one color sensor
    bool active;
    DONUT_COLOR target_color;
};

}

#endif // INTAKE_H