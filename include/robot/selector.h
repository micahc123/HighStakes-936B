#ifndef SELECTOR_H
#define SELECTOR_H

#include "pros/llemu.hpp"
#include "robot/intake.h"
#include "robot/auton.h"
#include "display/lv_core/lv_obj.h"
#include "display/lv_objx/lv_btnm.h"
#include "display/lv_objx/lv_tabview.h"

namespace subsystems {

enum class RING_COLOR {
    RED,
    BLUE,
    NONE
};

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
    RING_COLOR selected_ring_color;

    // LVGL objects
    lv_obj_t* tabview;
    lv_obj_t* red_btnm;
    lv_obj_t* blue_btnm;
    lv_obj_t* ring_btnm;
    lv_obj_t* skills_btnm;
    
    // Status labels
    lv_obj_t* auton_status;
    lv_obj_t* color_status;
    lv_obj_t* ring_status;
    lv_obj_t* skills_status;

    // UI methods
    void create_tab_view();
    void create_auton_tabs();
    void create_color_tab();
    void create_ring_tab();
    void create_skills_tab();
    
    static lv_res_t red_btnm_action(lv_obj_t* btnm, const char* txt);
    static lv_res_t blue_btnm_action(lv_obj_t* btnm, const char* txt);
    static lv_res_t ring_btnm_action(lv_obj_t* btnm, const char* txt);
    static lv_res_t skills_btnm_action(lv_obj_t* btnm, const char* txt);
    
    // Helper methods
    void update_auton_status(const char* status);
    void update_color_status(const char* status);
    void update_ring_status(const char* status);
    void update_skills_status(const char* status);
    
    // Screen dimensions
    static constexpr int SCREEN_WIDTH = 480;
    static constexpr int SCREEN_HEIGHT = 240;
    static constexpr int BUTTON_WIDTH = 450;
    static constexpr int BUTTON_HEIGHT = 50;
    static constexpr int STATUS_OFFSET = 30;

    friend lv_res_t skills_button_action(lv_obj_t* btnm, const char* txt);
};

}

#endif // SELECTOR_H