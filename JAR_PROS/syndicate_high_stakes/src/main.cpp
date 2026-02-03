#include "main.h"

//Motor Definitions
pros::Motor left_front_mtr(-5, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor left_middle_mtr(-6, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor left_back_mtr(-19, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor right_front_mtr(9, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor right_middle_mtr(10, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor right_back_mtr(20, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor intake_mtrl(8, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor intake_mtrr(-12, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
//hi
//Chassis constructor
Drive chassis(
  //Left Motors:
  {left_front_mtr.get_port(), left_middle_mtr.get_port(), left_back_mtr.get_port()},
  //Right Motors:
  {right_front_mtr.get_port(), right_middle_mtr.get_port(), right_back_mtr.get_port()},
  //IMU Port:
  18,
  //Wheel diameter (4" omnis are actually closer to 4.125"):
  4.125,
  //External Gear Ratio
  0.75,
  //Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
  360
);

Intake intake(
	{intake_mtrl.get_port(), intake_mtrr.get_port()}
);

Pneumatics pneumatics(
	{clench, climb}
);

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	pros::lcd::initialize();
	chassis.initialize();
	intake.initialize();
	pneumatics.clench_initialize();
	pneumatics.climb_initialize();
}

void disabled() {}

int current_auton_selection = 2;
bool auto_started = false;

void competition_initialize() {
  while(auto_started == false){            //Changing the names below will only change their names on the
    pros::screen::erase();                 //brain screen for auton selection.
    switch(current_auton_selection){       //Tap the brain screen to cycle through autons.
      case 0:
        pros::screen::print(TEXT_LARGE, 50, 50, "RedAWP");
        break;
      case 1:
        pros::screen::print(TEXT_LARGE, 50, 50, "BlueAWP");
        break;
      case 2:
        pros::screen::print(TEXT_LARGE, 50, 50, "Red Elim");
        break;
      case 3:
        pros::screen::print(TEXT_LARGE, 50, 50, "Blue Elim");
        break;
    }
    if(pros::screen::touch_status().touch_status == TOUCH_PRESSED){
      current_auton_selection ++;
      while(pros::screen::touch_status().touch_status == TOUCH_PRESSED  || pros::screen::touch_status().touch_status == TOUCH_HELD) {pros::delay(10);}
    } else if (current_auton_selection == 4){
      current_auton_selection = 0;
    }
    pros::Task::delay(10);
    }
}
void autonomous() {
  auto_started = true;
  chassis.set_brake_mode('H');
  switch(current_auton_selection){  
    case 0:
      redSWP(); //This is the default auton, if you don't select from the brain.
      break;        //Change these to be your own auton functions in order to use the auton selector.
    case 1:         //Tap the screen to cycle through autons.
      blueSWP();
      break;
    case 2:
      redElim();
      break;
    case 3:
      blueElim();
      break;
 }
 chassis.set_brake_mode('C');
}

void opcontrol(void) {
  chassis.set_brake_mode('C');
  while (1) {
    chassis.arcade_control();
    //chassis.tank_control();
    //chassis.arcade_control_double();
		intake.intake_control();
		pneumatics.clench_control();
    //pneumatics.climb_control();
    pros::delay(util::DELAY_TIME); 
  }
}