#include "robot/selector.h"

namespace subsystems {

Selector::Selector(Intake* intake) 
    : intake(intake), current_page(COLOR_PAGE) {}

void Selector::init() {
    pros::lcd::initialize();
    draw_color_selector();
}

void Selector::update() {
    if (current_page == COLOR_PAGE) {
        handle_color_selection();
    }
}

void Selector::draw_color_selector() {
    pros::lcd::clear();
    pros::lcd::set_text(0, "Color Selection");
    pros::lcd::set_text(1, "Left = Red");
    pros::lcd::set_text(2, "Right = Blue");
}

void Selector::handle_color_selection() {
    if (pros::lcd::read_buttons() & LCD_BTN_LEFT) {
        intake->set_target_color(DONUT_COLOR::RED);
        pros::lcd::set_text(4, "Selected: RED");
    } else if (pros::lcd::read_buttons() & LCD_BTN_RIGHT) {
        intake->set_target_color(DONUT_COLOR::BLUE);
        pros::lcd::set_text(4, "Selected: BLUE");
    }
}

}