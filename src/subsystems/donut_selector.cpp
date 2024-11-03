#include "robot/donut_selector.h"
#include "globals.h"

namespace subsystems {

DONUT_COLOR DonutSelector::selected_color = DONUT_COLOR::NONE;

lv_obj_t* DonutSelector::screen = nullptr;
lv_obj_t* DonutSelector::title_label = nullptr;
lv_obj_t* DonutSelector::red_btn = nullptr;
lv_obj_t* DonutSelector::blue_btn = nullptr;

void DonutSelector::init() {
    screen = lv_obj_create(NULL, NULL);
    lv_obj_set_size(screen, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_style(screen, &lv_style_plain_color);

    title_label = lv_label_create(screen, NULL);
    lv_label_set_text(title_label, "Select Donut Color");
    lv_obj_align(title_label, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);

    red_btn = lv_btn_create(screen, NULL);
    lv_obj_align(red_btn, NULL, LV_ALIGN_CENTER, -60, 0);
    lv_obj_t* red_label = lv_label_create(red_btn, NULL);
    lv_label_set_text(red_label, "Red");
    lv_btn_set_action(red_btn, LV_BTN_ACTION_CLICK, btn_red_callback);

    blue_btn = lv_btn_create(screen, NULL);
    lv_obj_align(blue_btn, NULL, LV_ALIGN_CENTER, 60, 0);
    lv_obj_t* blue_label = lv_label_create(blue_btn, NULL);
    lv_label_set_text(blue_label, "Blue");
    lv_btn_set_action(blue_btn, LV_BTN_ACTION_CLICK, btn_blue_callback);
}

void DonutSelector::show() {
    lv_scr_load(screen);
}

lv_res_t DonutSelector::btn_red_callback(lv_obj_t* btn) {
    selected_color = DONUT_COLOR::RED;
    intake.set_target_color(DONUT_COLOR::RED);
    lv_scr_load(lv_scr_act());
    return LV_RES_OK;
}

lv_res_t DonutSelector::btn_blue_callback(lv_obj_t* btn) {
    selected_color = DONUT_COLOR::BLUE;  
    intake.set_target_color(DONUT_COLOR::BLUE);
    lv_scr_load(lv_scr_act());
    return LV_RES_OK;
}

} // namespace subsystems