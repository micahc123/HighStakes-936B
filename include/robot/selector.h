 #ifndef SELECTOR_H
#define SELECTOR_H

#include "pros/llemu.hpp"
#include "robot/intake.h"
#include "robot/auton.h"

namespace subsystems {

class Selector {
public:
    Selector(Intake* intake, Auton* auton);
    void init();  
    void update();
    
private:
    Intake* intake;
    Auton* auton;
    AUTON_ROUTINE selected_auton;
    DONUT_COLOR selected_color;
    void draw_selector_screen(); 
    void handle_selection();      
};

}

#endif // SELECTOR_H