  #include "main.h"

  //ports
  #define PNEUMATICS_PORT 'H'
  #define LEFT_MOTOR_1 11
  #define LEFT_MOTOR_2 12
  #define RIGHT_MOTOR_1 1
  #define RIGHT_MOTOR_2 2
  #define INTAKE_MOTOR_1 8
  #define INTAKE_MOTOR_2 9

  //motor groups initialized here 
  auto leftMotors = MotorGroup({LEFT_MOTOR_1, LEFT_MOTOR_2}); 
  auto rightMotors = MotorGroup({RIGHT_MOTOR_1, RIGHT_MOTOR_2});
  auto intakeMotors = MotorGroup({INTAKE_MOTOR_1, INTAKE_MOTOR_2});

  //drive is initialized here
  auto drive = ChassisControllerBuilder()
      .withMotors(leftMotors, rightMotors) 
      .withDimensions(AbstractMotor::gearset::blue, {{4_in, 10_in}, imev5BlueTPR})
      .withOdometry()
      .buildOdometry();


  //controller, joystick state, and piston is initialized here
  Controller master;
  pros::ADIDigitalOut piston(PNEUMATICS_PORT);

  //odom test
  pros::Task positionTrackingTask([](){
      while (true) {
          auto state = drive->getState();

          // Print the state to the VEX brain
          pros::lcd::print(0, "x pos: %.2f", state.x.convert(inch));
          pros::lcd::print(1, "y pos: %.2f", state.y.convert(inch));
          pros::lcd::print(2, "Theta: %.2f", state.theta.convert(degree));

          pros::delay(10);
      }
  });

void opcontrol() {

  //piston state
  bool pistonState = false, prevPistonState = false;
  bool intakeState = false, prevIntakeState = false;


  while (true) {

    //movement values
    double left = -master.getAnalog(ControllerAnalog::leftY);
    double right = master.getAnalog(ControllerAnalog::rightY);


    //base movement
    drive->getModel()->tank(left, right);

    //pneumatics
    bool currentPistonState = master.getDigital(ControllerDigital::R1);
    if (currentPistonState && !prevPistonState){
        pistonState = !pistonState;
            if (pistonState) piston.set_value(true);
            else piston.set_value(false);
    }
    prevPistonState = currentPistonState;

    //intake
    bool currentAState = master.getDigital(ControllerDigital::A);
  if (currentAState && !prevIntakeState) {
    intakeState = !intakeState;
    if (intakeState) {
      intakeMotors.moveVoltage(500);
    } else {
      intakeMotors.moveVoltage(0);
    }
  }
  prevIntakeState = currentAState;
    

    pros::delay(20);
  }
}


 void autonomous(){
    Point point1 = Point{0_ft, 0_ft};
    drive->driveToPoint(point1);
  }



