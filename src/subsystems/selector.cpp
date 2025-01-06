#include "robot/selector.h"
#include "pros/screen.hpp"
#include "display/lv_core/lv_obj.h"
#include "display/lv_objx/lv_label.h"
#include "display/lv_objx/lv_tabview.h"
#include "display/lv_objx/lv_btnm.h"
#include "display/lv_themes/lv_theme.h"
#include <cstring>

namespace subsystems {

static const char* const auton_map[] = {"Left", "Right", "Do Nothing", ""};
static const char* const color_map[] = {"Red Donut", "Blue Donut", ""};
static const char* const ring_map[] = {"Red Ring", "Blue Ring", "None", ""};
static const char* const skills_map[] = {"Skills Run", ""};

Selector::Selector(Intake* intake, Auton* auton)
    : intake(intake), auton(auton), selected_auton(AUTON_ROUTINE::NONE), 
      selected_color(DONUT_COLOR::NONE), selected_ring_color(RING_COLOR::NONE) {}

void Selector::init() {
    lv_theme_t* th = lv_theme_alien_init(360, NULL);
    lv_theme_set_current(th);
    
    create_tab_view();
    create_auton_tabs();
    create_color_tab();
    create_ring_tab();
    create_skills_tab();
    
    update_auton_status("No auton selected");
    update_color_status("No target color selected");
    update_ring_status("No ring color selected");
    update_skills_status("Skills not selected");
}

void Selector::update() {
    pros::delay(10);
}

void Selector::create_tab_view() {
    tabview = lv_tabview_create(lv_scr_act(), NULL);
}

void Selector::create_auton_tabs() {
    lv_obj_t* red_tab = lv_tabview_add_tab(tabview, "Red");
    lv_obj_t* blue_tab = lv_tabview_add_tab(tabview, "Blue");
    
    red_btnm = lv_btnm_create(red_tab, NULL);
    lv_btnm_set_map(red_btnm, const_cast<const char**>(auton_map));
    lv_btnm_set_action(red_btnm, red_btnm_action);
    lv_btnm_set_toggle(red_btnm, true, false);  
    lv_obj_set_size(red_btnm, BUTTON_WIDTH, BUTTON_HEIGHT);
    lv_obj_align(red_btnm, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);
    lv_obj_set_free_ptr(red_btnm, this);
    
    auton_status = lv_label_create(red_tab, NULL);
    lv_obj_align(auton_status, red_btnm, LV_ALIGN_OUT_BOTTOM_MID, 0, STATUS_OFFSET);
    
    blue_btnm = lv_btnm_create(blue_tab, NULL);
    lv_btnm_set_map(blue_btnm, const_cast<const char**>(auton_map));
    lv_btnm_set_action(blue_btnm, blue_btnm_action);
    lv_btnm_set_toggle(blue_btnm, true, false); 
    lv_obj_set_size(blue_btnm, BUTTON_WIDTH, BUTTON_HEIGHT);
    lv_obj_align(blue_btnm, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);
    lv_obj_set_free_ptr(blue_btnm, this);
}

void Selector::create_color_tab() {
    lv_obj_t* color_tab = lv_tabview_add_tab(tabview, "Target Color");
    
    lv_obj_t* color_btnm = lv_btnm_create(color_tab, NULL);
    lv_btnm_set_map(color_btnm, const_cast<const char**>(color_map));
    lv_btnm_set_toggle(color_btnm, true, false); 
    lv_obj_set_size(color_btnm, BUTTON_WIDTH, BUTTON_HEIGHT);
    lv_obj_align(color_btnm, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);
    
    color_status = lv_label_create(color_tab, NULL);
    lv_obj_align(color_status, color_btnm, LV_ALIGN_OUT_BOTTOM_MID, 0, STATUS_OFFSET);
    
    lv_btnm_set_action(color_btnm, [](lv_obj_t* btnm, const char* txt) -> lv_res_t {
        Selector* selector = (Selector*)lv_obj_get_free_ptr(btnm);
        if (strcmp(txt, "Red Donut") == 0) {
            selector->selected_color = DONUT_COLOR::RED;
            selector->intake->set_target_color(selector->selected_color);
            selector->update_color_status("Red donut target selected");
        } else if (strcmp(txt, "Blue Donut") == 0) {
            selector->selected_color = DONUT_COLOR::BLUE;
            selector->intake->set_target_color(selector->selected_color);
            selector->update_color_status("Blue donut target selected");
        }
        return LV_RES_OK;
    });
    lv_obj_set_free_ptr(color_btnm, this);
}

void Selector::create_ring_tab() {
    lv_obj_t* ring_tab = lv_tabview_add_tab(tabview, "Ring Color");
    
    ring_btnm = lv_btnm_create(ring_tab, NULL);
    lv_btnm_set_map(ring_btnm, const_cast<const char**>(ring_map));
    lv_btnm_set_action(ring_btnm, ring_btnm_action);
    lv_btnm_set_toggle(ring_btnm, true, false);  
    lv_obj_set_size(ring_btnm, BUTTON_WIDTH, BUTTON_HEIGHT);
    lv_obj_align(ring_btnm, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);
    lv_obj_set_free_ptr(ring_btnm, this);
    
    ring_status = lv_label_create(ring_tab, NULL);
    lv_obj_align(ring_status, ring_btnm, LV_ALIGN_OUT_BOTTOM_MID, 0, STATUS_OFFSET);
}

void Selector::create_skills_tab() {
    lv_obj_t* skills_tab = lv_tabview_add_tab(tabview, "Skills");
    
    skills_btnm = lv_btnm_create(skills_tab, NULL);
    lv_btnm_set_map(skills_btnm, const_cast<const char**>(skills_map));
    lv_btnm_set_action(skills_btnm, skills_btnm_action);
    lv_btnm_set_toggle(skills_btnm, true, false);  // Enable toggle mode
    lv_obj_set_size(skills_btnm, BUTTON_WIDTH, BUTTON_HEIGHT);
    lv_obj_align(skills_btnm, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);
    
    skills_status = lv_label_create(skills_tab, NULL);
    lv_obj_align(skills_status, skills_btnm, LV_ALIGN_OUT_BOTTOM_MID, 0, STATUS_OFFSET);
    lv_obj_set_free_ptr(skills_btnm, this);
}

lv_res_t Selector::red_btnm_action(lv_obj_t* btnm, const char* txt) {
    Selector* selector = (Selector*)lv_obj_get_free_ptr(btnm);
    if (strcmp(txt, "Left") == 0) {
        selector->selected_auton = AUTON_ROUTINE::RED_LEFT;
        selector->update_auton_status("Red Left auton selected");
    } else if (strcmp(txt, "Right") == 0) {
        selector->selected_auton = AUTON_ROUTINE::RED_RIGHT;
        selector->update_auton_status("Red Right auton selected");
    } else {
        selector->selected_auton = AUTON_ROUTINE::NONE;
        selector->update_auton_status("No auton selected");
    }
    selector->auton->set_selected_auton(selector->selected_auton);
    return LV_RES_OK;
}

lv_res_t Selector::blue_btnm_action(lv_obj_t* btnm, const char* txt) {
    Selector* selector = (Selector*)lv_obj_get_free_ptr(btnm);
    if (strcmp(txt, "Left") == 0) {
        selector->selected_auton = AUTON_ROUTINE::BLUE_LEFT;
        selector->update_auton_status("Blue Left auton selected");
    } else if (strcmp(txt, "Right") == 0) {
        selector->selected_auton = AUTON_ROUTINE::BLUE_RIGHT;
        selector->update_auton_status("Blue Right auton selected");
    } else {
        selector->selected_auton = AUTON_ROUTINE::NONE;
        selector->update_auton_status("No auton selected");
    }
    selector->auton->set_selected_auton(selector->selected_auton);
    return LV_RES_OK;
}

lv_res_t Selector::ring_btnm_action(lv_obj_t* btnm, const char* txt) {
    Selector* selector = (Selector*)lv_obj_get_free_ptr(btnm);
    if (strcmp(txt, "Red Ring") == 0) {
        selector->selected_ring_color = RING_COLOR::RED;
        selector->update_ring_status("Red ring selected");
    } else if (strcmp(txt, "Blue Ring") == 0) {
        selector->selected_ring_color = RING_COLOR::BLUE;
        selector->update_ring_status("Blue ring selected");
    } else {
        selector->selected_ring_color = RING_COLOR::NONE;
        selector->update_ring_status("No ring color selected");
    }
    return LV_RES_OK;
}

lv_res_t Selector::skills_btnm_action(lv_obj_t* btnm, const char* txt) {
    Selector* selector = (Selector*)lv_obj_get_free_ptr(btnm);
    if (strcmp(txt, "Skills Run") == 0) {
        selector->selected_auton = AUTON_ROUTINE::SKILLS;
        selector->auton->set_selected_auton(selector->selected_auton);
        selector->update_auton_status("Skills autonomous selected");
        selector->update_skills_status("Skills mode activated");
    }
    return LV_RES_OK;
}

void Selector::update_auton_status(const char* status) {
    lv_label_set_text(auton_status, status);
}

void Selector::update_color_status(const char* status) {
    lv_label_set_text(color_status, status);
}

void Selector::update_ring_status(const char* status) {
    lv_label_set_text(ring_status, status);
}

void Selector::update_skills_status(const char* status) {
    lv_label_set_text(skills_status, status);
}

}