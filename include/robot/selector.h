#ifndef SELECTOR_H
#define SELECTOR_H

#include "pros/llemu.hpp"
#include "robot/intake.h"

namespace subsystems {

class Selector {
public:
    Selector(Intake* intake);
    void init();
    void update();
    
private:
    static constexpr int COLOR_PAGE = 0;
    Intake* intake;
    int current_page;
    void draw_color_selector();
    void handle_color_selection();
};

}

#endif // SELECTOR_H