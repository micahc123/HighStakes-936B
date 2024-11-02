#ifndef AUTON_SELECTOR_H
#define AUTON_SELECTOR_H

#include "api.h"
#include "pros/rtos.hpp"
#include "pros/llemu.hpp"
#include <string>

enum class AUTON_ROUTINE { RED_LEFT, RED_RIGHT, BLUE_LEFT, BLUE_RIGHT };

class AutonSelector {
public:
    static void init();
    static void update_display();
    static AUTON_ROUTINE get_selected_auton();
    
private:
    static AUTON_ROUTINE selected_auton;
    static std::string auton_names[];
    static int current_selection;
    
    static lv_obj_t* title_label;
    static lv_obj_t* selection_label;
    static lv_obj_t* btn_left;
    static lv_obj_t* btn_right;
    static lv_obj_t* btn_confirm;
    
    static lv_res_t btn_left_callback(lv_obj_t* btn);
    static lv_res_t btn_right_callback(lv_obj_t* btn);
    static lv_res_t btn_confirm_callback(lv_obj_t* btn);
};

#endif // AUTON_SELECTOR_H