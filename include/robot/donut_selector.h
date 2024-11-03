#ifndef DONUT_SELECTOR_H
#define DONUT_SELECTOR_H

#include "api.h"
#include "robot/intake.h"

namespace subsystems {

class DonutSelector {
public:
    static void init();
    static void show();

private:
    static DONUT_COLOR selected_color;
    
    static lv_obj_t* screen;
    static lv_obj_t* title_label;
    static lv_obj_t* red_btn;
    static lv_obj_t* blue_btn;
    
    static lv_res_t btn_red_callback(lv_obj_t* btn);
    static lv_res_t btn_blue_callback(lv_obj_t* btn);
};

} // namespace subsystems

#endif // DONUT_SELECTOR_H