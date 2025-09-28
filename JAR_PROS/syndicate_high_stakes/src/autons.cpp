#include "main.h"

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
   chassis.set_drive_constants(10, 0.5, 0,0, 0);
  chassis.set_heading_constants(2, .019, 0, 0, 0);
  chassis.set_turn_constants(10, 0.27, 0, 2.75, 0);
  chassis.set_swing_constants(10, 0.4, 0, 3.5, 0);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1, 300, 5000);
  chassis.set_turn_exit_conditions(2, 300, 3000);
  chassis.set_swing_exit_conditions(2, 300, 3000);
}

void drive_test(){
  default_constants();
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

void turn_test(){
  default_constants();
  chassis.turn_to_angle(5, 8);
  chassis.turn_to_angle(30, 8);
  chassis.turn_to_angle(90, 8);
  chassis.turn_to_angle(225, 8);
  chassis.turn_to_angle(0, 8);
}

void swing_test(){
  default_constants();
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  default_constants();
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void redSWP(){}

void blueSWP(){}

void redElim(){}

void blueElim(){}

void skills(){
  default_constants();
  chassis.set_heading(180);
  //starts backwards
  //score on alliance stake 
  chassis.drive_distance(-24);
  chassis.turn_to_angle(90);
  chassis.drive_distance(24);
  pneumatics.clench_v(1);
  chassis.drive_distance(6);
  chassis.turn_to_angle(180);
  intake.move(120);
  chassis.drive_distance(-24);
  chassis.turn_to_angle(270);
  chassis.drive_distance(-24);
  chassis.turn_to_angle(0);
  chassis.drive_distance(-36);
  chassis.turn_to_angle(225);
  chassis.drive_distance(-17);
  chassis.turn_to_angle(315);
  
}