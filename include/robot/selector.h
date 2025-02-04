#ifndef SELECTOR_H
#define SELECTOR_H

#include "pros/screen.hpp"
#include "display/lv_core/lv_obj.h"
#include "display/lv_objx/lv_label.h"
#include "display/lv_objx/lv_tabview.h"
#include "display/lv_objx/lv_btnm.h"
#include "robot/auton.h"
#include "robot/intake.h"

namespace subsystems {

class Selector {
public:
    Selector(Intake* intake, Auton* auton);
    void init();
    void update();

private:
    static constexpr int MAX_AUTONS = 10;
    static constexpr int BUTTON_WIDTH = 450;
    static constexpr int BUTTON_HEIGHT = 50;
    static constexpr int BUTTON_Y_POS = 100;
    static constexpr int DEBUG_LABEL_SPACING = 30;

    void setup_button_maps(const char** autons);
    void create_tab_view();
    void create_auton_tabs();
    void create_skills_tab();
    void create_color_tab();
    void create_debug_tab();
    void update_debug_info();
    void start_tab_watcher();

    static void tab_watcher_fn(void* param);
    static lv_res_t red_btnm_action(lv_obj_t* btnm, const char* txt);
    static lv_res_t blue_btnm_action(lv_obj_t* btnm, const char* txt);
    static lv_res_t skills_btn_action(lv_obj_t* btn);
    static lv_res_t color_btnm_action(lv_obj_t* btnm, const char* txt);

    Intake* intake;
    Auton* auton;
    AUTON_ROUTINE selected_auton;
    DONUT_COLOR selected_color;
    int auton_count;

    lv_obj_t* tabview;
    lv_obj_t* red_btnm;
    lv_obj_t* blue_btnm;
    lv_obj_t* skills_btn;
    lv_obj_t* color_btnm;
    lv_obj_t* debug_hue_label;
    lv_obj_t* debug_auton_label;
    lv_obj_t* debug_color_label;
    lv_obj_t* debug_ring_label;
    lv_obj_t* debug_detection_label;

    const char* btnm_map[MAX_AUTONS + 1];
};

}

#endif // SELECTOR_H