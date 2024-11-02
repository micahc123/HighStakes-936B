#ifndef WALL_H
#define WALL_H


namespace subsystems {

class Wall {
public:
    Wall(int motor_port);
    void move_forward();
    void move_backward();
    void stop();
    void run();
    bool is_active() const;
    void activate();
    void deactivate();

private:
    pros::Motor wall_motor;
    bool active = false;
};
}

#endif // WALL_H