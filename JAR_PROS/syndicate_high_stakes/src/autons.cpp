#include "main.h"

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
   chassis.set_drive_constants(10, 2, 0, 0, 0);
  chassis.set_heading_constants(2, .019, 0, 0, 0);
  chassis.set_turn_constants(10, 0.27, 0, 2.75, 0);
  chassis.set_swing_constants(10, 0.4, 0, 3.5, 0);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1, 300, 5000);
  chassis.set_turn_exit_conditions(2, 300, 3000);
  chassis.set_swing_exit_conditions(2, 300, 3000);
}

void left() {
  chassis.drive_distance(48);
}

void right() {

}

void soloAWP() {

}

void otherpersonAWP() {

}

void skills() {

}