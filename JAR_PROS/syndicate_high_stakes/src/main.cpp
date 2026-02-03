#include "main.h"

//Motor Definitions
pros::Motor left_front_mtr(-18, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor left_middle_mtr(-20, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor left_back_mtr(-16, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor right_front_mtr(13, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor right_middle_mtr(12, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor right_back_mtr(11, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor intake_motor(8, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor outtake_motor(-10, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::ADIDigitalOut matchload('A');
pros::ADIDigitalOut wing('B');
pros::ADIDigitalOut middle('D');
//hi
//Chassis constructor
Drive chassis(
  //Left Motors:
  {left_front_mtr.get_port(), left_middle_mtr.get_port(), left_back_mtr.get_port()},
  //Right Motors:
  {right_front_mtr.get_port(), right_middle_mtr.get_port(), right_back_mtr.get_port()},
  //IMU Port:
  2,
  //Wheel diameter (4" omnis are actually closer to 4.125"):
  3.25,
  //External Gear Ratio
  0.75,
  //Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
  358.5
);

Intake intake(
	{intake_motor.get_port(), outtake_motor.get_port()}
);

Pneumatics pneumatics(
	{matchload, wing, middle}
);

void initialize() {
	pros::lcd::initialize();
	chassis.initialize();
	intake.initialize();
	pneumatics.matchload_initialize();
	pneumatics.wing_initialize();
	pneumatics.middle_initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  chassis.set_brake_mode('H');
      left();
      //right();
      //otherpersonAWP();
      //soloAWP();
      //skills();
}

void opcontrol(void) {
  chassis.set_brake_mode('H');
  while (1) {
    //chassis.arcade_control();
    //chassis.tank_control();
    chassis.arcade_control_double();
		intake.intake_control();
		pneumatics.matchload_control();
		pneumatics.wing_control();
		pneumatics.middle_control();
    pros::delay(util::DELAY_TIME); 
  }
}