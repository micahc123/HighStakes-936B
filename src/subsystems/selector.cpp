#include "robot/selector.h"
#include "pros/screen.hpp"
#include "display/lv_core/lv_obj.h"
#include "display/lv_objx/lv_label.h"

namespace subsystems {

Selector::Selector(Intake* intake, Auton* auton)
    : intake(intake), auton(auton), selected_auton(AUTON_ROUTINE::NONE), selected_color(DONUT_COLOR::NONE) {}

void Selector::init() {
    draw_selector_screen();
}

void Selector::update() {
    handle_selection();
}

void Selector::draw_selector_screen() {
    lv_obj_t* screen = lv_scr_act();
    lv_obj_set_style(screen, &lv_style_plain_color);

    // Define the red and blue button styles
    static lv_style_t style_btn_red;
    lv_style_copy(&style_btn_red, &lv_style_plain);
    style_btn_red.body.main_color = LV_COLOR_RED;
    style_btn_red.body.grad_color = LV_COLOR_RED;

    static lv_style_t style_btn_blue;
    lv_style_copy(&style_btn_blue, &lv_style_plain);
    style_btn_blue.body.main_color = LV_COLOR_BLUE;
    style_btn_blue.body.grad_color = LV_COLOR_BLUE;

    // Draw the autonomous selection buttons
    lv_obj_t* red_auton_btn = lv_btn_create(screen, NULL);
    lv_obj_set_size(red_auton_btn, 240, 120);
    lv_obj_set_pos(red_auton_btn, 0, 0);
    lv_obj_set_style(red_auton_btn, &style_btn_red);

    lv_obj_t* blue_auton_btn = lv_btn_create(screen, NULL);
    lv_obj_set_size(blue_auton_btn, 240, 120);
    lv_obj_set_pos(blue_auton_btn, 240, 0);
    lv_obj_set_style(blue_auton_btn, &style_btn_blue);

    lv_obj_t* red_auton_label = lv_label_create(red_auton_btn, NULL);
    lv_label_set_text(red_auton_label, "Red");
    lv_obj_align(red_auton_label, NULL, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t* blue_auton_label = lv_label_create(blue_auton_btn, NULL);
    lv_label_set_text(blue_auton_label, "Blue");
    lv_obj_align(blue_auton_label, NULL, LV_ALIGN_CENTER, 0, 0);

    // Draw the color selection buttons
    lv_obj_t* red_color_btn = lv_btn_create(screen, NULL);
    lv_obj_set_size(red_color_btn, 240, 120);
    lv_obj_set_pos(red_color_btn, 0, 120);
    lv_obj_set_style(red_color_btn, &style_btn_red);

    lv_obj_t* blue_color_btn = lv_btn_create(screen, NULL);
    lv_obj_set_size(blue_color_btn, 240, 120);
    lv_obj_set_pos(blue_color_btn, 240, 120);
    lv_obj_set_style(blue_color_btn, &style_btn_blue);

    lv_obj_t* red_color_label = lv_label_create(red_color_btn, NULL);
    lv_label_set_text(red_color_label, "Red");
    lv_obj_align(red_color_label, NULL, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t* blue_color_label = lv_label_create(blue_color_btn, NULL);
    lv_label_set_text(blue_color_label, "Blue");
    lv_obj_align(blue_color_label, NULL, LV_ALIGN_CENTER, 0, 0);
}

void Selector::handle_selection() {
    pros::screen_touch_status_s_t status;

    if (status.touch_status == 1) {
        // Handle auton selection
        if (status.y < 120) {
            if (status.x < 240) {
                selected_auton = AUTON_ROUTINE::RED_LEFT;
                lv_obj_t* label = lv_label_create(lv_scr_act(), NULL);
                lv_label_set_text(label, "Red Left");
                lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 60);
            } else {
                selected_auton = AUTON_ROUTINE::BLUE_LEFT;
                lv_obj_t* label = lv_label_create(lv_scr_act(), NULL);
                lv_label_set_text(label, "Blue Left");
                lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 60);
            }
        }

        // Handle color selection
        if (status.y >= 120) {
            if (status.x < 240) {
                selected_color = DONUT_COLOR::RED;
                lv_obj_t* label = lv_label_create(lv_scr_act(), NULL);
                lv_label_set_text(label, "Red");
                lv_obj_align(label, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -60);
            } else {
                selected_color = DONUT_COLOR::BLUE;
                lv_obj_t* label = lv_label_create(lv_scr_act(), NULL);
                lv_label_set_text(label, "Blue");
                lv_obj_align(label, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -60);
            }
        }

        // Confirm selection
        if (selected_auton != AUTON_ROUTINE::NONE && selected_color != DONUT_COLOR::NONE) {
            intake->set_target_color(selected_color);
            auton->set_selected_auton(selected_auton);
            lv_obj_t* label = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_text(label, "Selection Confirmed!");
            lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
        }
    }

    pros::delay(10);
}
}