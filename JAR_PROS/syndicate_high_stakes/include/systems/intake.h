#include "main.h"

class Intake{
    public:
    pros::Motor intake;
    pros::Motor outtake;

    Intake(std::int8_t intake_port, std::int8_t outtake_port);

    void intake_control();
    void initialize();
    void move(float velocity);
        
};