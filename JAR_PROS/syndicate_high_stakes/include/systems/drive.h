#include "main.h"

class Drive
{
private:
  float wheel_diameter;
  float wheel_ratio;
  float gyro_scale;
  float TPI;
  float in_to_deg;

public:
  //Controller joystics won't record unless values greater than 5
  int deadzone = 5;
  pros::MotorGroup DriveL;
  pros::MotorGroup DriveR;
  pros::Imu Gyro;

  //Turning variables
  float turn_max_voltage;
  float turn_kp;
  float turn_ki;
  float turn_kd;
  float turn_starti;
  float turn_settle_error;
  float turn_settle_time;
  float turn_timeout;

  //Driving variables
  float drive_max_voltage;
  float drive_kp;
  float drive_ki;
  float drive_kd;
  float drive_starti;
  float drive_settle_error;
  float drive_settle_time;
  float drive_timeout;

  //Heading variables
  float heading_max_voltage;
  float heading_kp;
  float heading_ki;
  float heading_kd;
  float heading_starti;

  //Swinging variables
  float swing_max_voltage;
  float swing_kp;
  float swing_ki;
  float swing_kd;
  float swing_starti;
  float swing_settle_error;
  float swing_settle_time;
  float swing_timeout;
  
  float desired_heading;

  Drive(std::initializer_list<std::int8_t> DriveL, std::initializer_list<std::int8_t> DriveR, int gyro_port, float wheel_diameter, float wheel_ratio, float gyro_scale);
  //Sensor Functions
  void reset_drive_sensor();
  float get_left_position_in();
  float get_right_position_in();

  //Gyro Functions
  bool imu_calibrate();
  float get_gyro();
  void reset_gyro();
  float get_absolute_heading();
  void set_heading(float heading);

  //Operation Functions
  void initialize();
  void set_brake_mode(char brake_type);
  void drive_with_voltage(float leftVoltage, float rightVoltage);
  void macro();

  //Joystick control methods
  void arcade_control();
  void arcade_control_double();
  void tank_control();

  //Set autonomous function constants
  void set_turn_constants(float turn_max_voltage, float turn_kp, float turn_ki, float turn_kd, float turn_starti); 
  void set_drive_constants(float drive_max_voltage, float drive_kp, float drive_ki, float drive_kd, float drive_starti);
  void set_heading_constants(float heading_max_voltage, float heading_kp, float heading_ki, float heading_kd, float heading_starti);
  void set_swing_constants(float swing_max_voltage, float swing_kp, float swing_ki, float swing_kd, float swing_starti);

  //Set autonomous function exit conditions
  void set_turn_exit_conditions(float turn_settle_error, float turn_settle_time, float turn_timeout);
  void set_drive_exit_conditions(float drive_settle_error, float drive_settle_time, float drive_timeout);
  void set_swing_exit_conditions(float swing_settle_error, float swing_settle_time, float swing_timeout);

  //Turning Functions
  void turn_to_angle(float angle);
  void turn_to_angle(float angle, float turn_max_voltage);
  void turn_to_angle(float angle, float turn_max_voltage, float turn_settle_error, float turn_settle_time, float turn_timeout, float turn_kp, float turn_ki, float turn_kd, float turn_starti);

  //Driving Functions
  void drive_distance(float distance);
  void drive_distance(float distance, float drive_max_voltage);
  void drive_distance(float distance, float heading, float drive_max_voltage, float heading_max_voltage);
  void drive_distance(float distance, float drive_max_voltage,float drive_settle_error, float drive_settle_time, float drive_timeout, float drive_kp, float drive_ki, float drive_kd, float drive_starti);
  void drive_distance(float distance, float heading, float drive_max_voltage, float heading_max_voltage, float drive_settle_error, float drive_settle_time, float drive_timeout, float drive_kp, float drive_ki, float drive_kd, float drive_starti, float heading_kp, float heading_ki, float heading_kd, float heading_starti);

  //Swinging Functions
  void left_swing_to_angle(float angle);
  void left_swing_to_angle(float angle, float swing_max_voltage);
  void left_swing_to_angle(float angle, float swing_max_voltage, float swing_settle_error, float swing_settle_time, float swing_timeout, float swing_kp, float swing_ki, float swing_kd, float swing_starti);
  void right_swing_to_angle(float angle);
  void right_swing_to_angle(float angle, float swing_max_voltage);
  void right_swing_to_angle(float angle, float swing_max_voltage, float swing_settle_error, float swing_settle_time, float swing_timeout, float swing_kp, float swing_ki, float swing_kd, float swing_starti);
};