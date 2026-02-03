#include "main.h"

Intake::Intake(std::int8_t intake_port, std::int8_t outtake_port) 
    : intake(intake_port),
    outtake(outtake_port) {}

void Intake::intake_control() {
    intake.move_velocity(0);
    outtake.move_velocity(0);
    if (master.get_digital(DIGITAL_R1)){ 
        intake.move_velocity(-600); }
    if (master.get_digital(DIGITAL_R2)){
        outtake.move_velocity(600); }
    if (master.get_digital(DIGITAL_L1)){
        intake.move_velocity(600);
        }
    if (master.get_digital(DIGITAL_L2)){
        outtake.move_velocity(-600);
        }
}

void Intake::initialize() {
    intake.set_brake_mode(MOTOR_BRAKE_COAST);
    outtake.set_brake_mode(MOTOR_BRAKE_BRAKE);
}

void Intake::move(float velocity) {
    intake.move_velocity(velocity);
}