#include "robot/auton_selector.h"

AUTON_ROUTINE AutonSelector::selected_auton = AUTON_ROUTINE::RED_LEFT;
int AutonSelector::current_selection = 0;

std::string AutonSelector::auton_names[] = {
    "Red Left",
    "Red Right",
    "Blue Left",
    "Blue Right"
};

lv_obj_t* AutonSelector::title_label = nullptr;
lv_obj_t* AutonSelector::selection_label = nullptr;
lv_obj_t* AutonSelector::btn_left = nullptr;
lv_obj_t* AutonSelector::btn_right = nullptr;
lv_obj_t* AutonSelector::btn_confirm = nullptr;

void AutonSelector::init() {

    title_label = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(title_label, "au Selection");
    lv_obj_align(title_label, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);

    selection_label = lv_label_create(lv_scr_act(), NULL);
    update_display();
    lv_obj_align(selection_label, NULL, LV_ALIGN_CENTER, 0, 0);

    btn_left = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_size(btn_left, 70, 50);
    lv_obj_align(btn_left, NULL, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_btn_set_action(btn_left, LV_BTN_ACTION_CLICK, btn_left_callback);
    lv_obj_t* label_left = lv_label_create(btn_left, NULL);
    lv_label_set_text(label_left, "←");

    btn_right = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_size(btn_right, 70, 50);
    lv_obj_align(btn_right, NULL, LV_ALIGN_IN_RIGHT_MID, -10, 0);
    lv_btn_set_action(btn_right, LV_BTN_ACTION_CLICK, btn_right_callback);
    lv_obj_t* label_right = lv_label_create(btn_right, NULL);
    lv_label_set_text(label_right, "→");

    btn_confirm = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_size(btn_confirm, 100, 50);
    lv_obj_align(btn_confirm, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -10);
    lv_btn_set_action(btn_confirm, LV_BTN_ACTION_CLICK, btn_confirm_callback);
    lv_obj_t* label_confirm = lv_label_create(btn_confirm, NULL);
    lv_label_set_text(label_confirm, "Confirm");
}

void AutonSelector::update_display() {
    if (selection_label != nullptr) {
        lv_label_set_text(selection_label, auton_names[current_selection].c_str());
    }
}

lv_res_t AutonSelector::btn_left_callback(lv_obj_t* btn) {
    current_selection = (current_selection - 1 + 4) % 4;
    update_display();
    return LV_RES_OK;
}

lv_res_t AutonSelector::btn_right_callback(lv_obj_t* btn) {
    current_selection = (current_selection + 1) % 4;
    update_display();
    return LV_RES_OK;
}

lv_res_t AutonSelector::btn_confirm_callback(lv_obj_t* btn) {
    selected_auton = static_cast<AUTON_ROUTINE>(current_selection);
    return LV_RES_OK;
}

AUTON_ROUTINE AutonSelector::get_selected_auton() {
    return selected_auton;
}