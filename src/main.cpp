#include "main.h"

//ports
#define PNEUMATICS_PORT 'A'
#define LEFT_MOTOR_1 11
#define LEFT_MOTOR_2 12
#define RIGHT_MOTOR_1 1
#define RIGHT_MOTOR_2 2


//qcf joystick state
enum class JoystickState {
  Center,
  Up,
  Down,
  Left
};

//motor groups initialized here 
auto leftMotors = MotorGroup({LEFT_MOTOR_1, LEFT_MOTOR_2}); 
auto rightMotors = MotorGroup({RIGHT_MOTOR_1, RIGHT_MOTOR_2});

//drive is initialized here
auto drive = ChassisControllerBuilder()
    .withMotors(leftMotors, rightMotors) 
    .withDimensions(AbstractMotor::gearset::blue, {{4_in, 10_in}, imev5BlueTPR})
    .build();


//controller, joystick state, and piston is initialized here
Controller master;
JoystickState state = JoystickState::Center;
pros::ADIDigitalOut piston(PNEUMATICS_PORT);


//pneumatics
void pneumatics(bool& state){
  if (master.getDigital(ControllerDigital::R1)) {
    state = !state;
    piston.set_value(state);
  }
}
//main loop
void opcontrol() {
  //initital state
  bool pistonState = false; 

  while (true) {
    double left = -master.getAnalog(ControllerAnalog::leftY);
    double right = master.getAnalog(ControllerAnalog::rightY);
    movement(left, right);

    //Macros
    qcf();
    
    //Pneumatics
    pneumatics(pistonState);

    pros::delay(20);
  }
}

//base movement
void movement(double left, double right){
    drive->getModel()->tank(left, right);
}
























//qcf
void qcf() {
  double leftX = master.getAnalog(ControllerAnalog::leftX);
  double leftY = master.getAnalog(ControllerAnalog::leftY);
  
  //180 degree turn
  if (leftY > 10 && abs(leftX) < 10) {
    state = JoystickState::Up;
  } else if (leftY < -10 && abs(leftX) < 10) {
    if (state == JoystickState::Up) {
      state = JoystickState::Down;
    }
  } else if (leftY < 10 && leftX < -10) {
    if (state == JoystickState::Down) {
      state = JoystickState::Left;
      drive->turnAngle(180_deg);
    }
  } else {
    state = JoystickState::Center;
  }
}