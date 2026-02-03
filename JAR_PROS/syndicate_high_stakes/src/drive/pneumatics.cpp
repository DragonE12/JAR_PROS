#include "main.h"


Pneumatics::Pneumatics(pros::adi::DigitalOut matchload_port, pros::adi::DigitalOut wing_port, pros::adi::DigitalOut middle_port)
   : matchload(matchload_port),
   wing(wing_port),
   middle(middle_port) {}

void Pneumatics::matchload_control() {
  if (master.get_digital_new_press(DIGITAL_Y)){
       matchload_down = !matchload_down;
       matchload.set_value(matchload_down);
   }
}  

void Pneumatics::matchload_v(int value) {
   matchload.set_value(value);
}

void Pneumatics::matchload_initialize() {
   matchload.set_value(0);
}

void Pneumatics::wing_control() {
  if (master.get_digital_new_press(DIGITAL_A)){
       wing_up = !wing_up;
       wing.set_value(wing_up);
   }
}

void Pneumatics::wing_v(int value) {
   wing.set_value(value);
}

void Pneumatics::wing_initialize() {
   wing.set_value(1);
}

void Pneumatics::middle_control() {
   if (master.get_digital_new_press(DIGITAL_X)){
        middle_up = !middle_up;
        middle.set_value(middle_up);
    }
 }  

void Pneumatics::middle_v(int value) {
   middle.set_value(value);
}

void Pneumatics::middle_initialize() {
   middle.set_value(1);
}

