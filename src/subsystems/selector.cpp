#include "robot/selector.h"
#include "robot/auton.h"

namespace subsystems {

Selector::Selector(Intake* intake, Auton* auton) 
    : intake(intake), auton(auton), current_page(AUTON_PAGE), selected_auton(AUTON_ROUTINE::NONE), selected_color(DONUT_COLOR::NONE) {}

void Selector::init() {
    pros::lcd::initialize();
    draw_auton_selector();
}

void Selector::update() {
    if (current_page == AUTON_PAGE) {
        handle_auton_selection();
    } else if (current_page == COLOR_PAGE) {
        handle_color_selection();
    }
}

void Selector::draw_auton_selector() {
    pros::lcd::clear();
    pros::lcd::set_text(0, "Auton Selection");
    pros::lcd::set_text(1, "Red Left");
    pros::lcd::set_text(2, "Red Right");
    pros::lcd::set_text(3, "Blue Left");
    pros::lcd::set_text(4, "Blue Right");
    pros::lcd::set_text(6, "Confirm");
}

void Selector::handle_auton_selection() {
    if (pros::lcd::read_buttons() & LCD_BTN_LEFT) {
        selected_auton = AUTON_ROUTINE::RED_LEFT;
        pros::lcd::set_text(5, "Selected: Red Left");
    } else if (pros::lcd::read_buttons() & LCD_BTN_RIGHT) {
        selected_auton = AUTON_ROUTINE::RED_RIGHT;
        pros::lcd::set_text(5, "Selected: Red Right");
    } else if (pros::lcd::read_buttons() & LCD_BTN_CENTER) {
        selected_auton = AUTON_ROUTINE::BLUE_LEFT;
        pros::lcd::set_text(5, "Selected: Blue Left");
    } else if (pros::lcd::read_buttons() & (LCD_BTN_LEFT | LCD_BTN_RIGHT)) {
        selected_auton = AUTON_ROUTINE::BLUE_RIGHT;
        pros::lcd::set_text(5, "Selected: Blue Right");
    }

    if (pros::lcd::read_buttons() & LCD_BTN_CENTER && selected_auton != AUTON_ROUTINE::NONE) {
        auton->set_selected_auton(selected_auton);
        current_page = COLOR_PAGE;
        draw_color_selector();
    }
}

void Selector::draw_color_selector() {
    pros::lcd::clear();
    pros::lcd::set_text(0, "Color Selection");
    pros::lcd::set_text(1, "Red");
    pros::lcd::set_text(2, "Blue");
    pros::lcd::set_text(4, "Confirm");
}

void Selector::handle_color_selection() {
    if (pros::lcd::read_buttons() & LCD_BTN_LEFT) {
        selected_color = DONUT_COLOR::RED;
        pros::lcd::set_text(3, "Selected: RED");
    } else if (pros::lcd::read_buttons() & LCD_BTN_RIGHT) {
        selected_color = DONUT_COLOR::BLUE;
        pros::lcd::set_text(3, "Selected: BLUE");
    }

    if (pros::lcd::read_buttons() & LCD_BTN_CENTER && selected_color != DONUT_COLOR::NONE) {
        intake->set_target_color(selected_color);
        pros::lcd::set_text(5, "Selection Confirmed!");
        current_page = AUTON_PAGE;
        draw_auton_selector();
    }
}

}