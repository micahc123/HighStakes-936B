#ifndef CLAMP_H
#define CLAMP_H


namespace subsystems {

class Clamp {
public:
    Clamp(char port);
    void toggle();
    void clamp_stake();
    void declamp_stake();
    void run();

    bool get_state() const;

private:
    pros::ADIDigitalOut piston;
    bool piston_toggle;
};

} // namespace subsystems

#endif // CLAMP_H