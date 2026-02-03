#include "main.h"

class Pneumatics{
   public:
   pros::adi::DigitalOut matchload;
   pros::adi::DigitalOut wing;
   pros::adi::DigitalOut middle;
   Pneumatics(pros::adi::DigitalOut matchload_port, pros::adi::DigitalOut wing_port, pros::adi::DigitalOut middle_port);

   void matchload_initialize();
   void matchload_control();
   void matchload_v(int value);

   void wing_initialize();
   void wing_control();
   void wing_v(int value);

   void middle_initialize();
   void middle_control();
   void middle_v(int value);
};