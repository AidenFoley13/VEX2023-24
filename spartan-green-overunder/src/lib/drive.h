#include "main.h"

#define FRONT_RIGHT_PORT 19
#define MIDDLE_RIGHT_PORT 18
#define BACK_RIGHT_PORT 20
#define FRONT_LEFT_PORT 14
#define MIDDLE_LEFT_PORT 12
#define BACK_LEFT_PORT 13

pros::Motor frontRight(FRONT_RIGHT_PORT, pros::E_MOTOR_GEAR_BLUE, true);
pros::Motor middleRight(MIDDLE_RIGHT_PORT, pros::E_MOTOR_GEAR_BLUE, true);
pros::Motor backRight(BACK_RIGHT_PORT, pros::E_MOTOR_GEAR_BLUE, true);
pros::Motor frontLeft(FRONT_LEFT_PORT, pros::E_MOTOR_GEAR_BLUE);
pros::Motor middleLeft(MIDDLE_LEFT_PORT, pros::E_MOTOR_GEAR_BLUE);
pros::Motor backLeft(BACK_LEFT_PORT, pros::E_MOTOR_GEAR_BLUE);

void brake(pros::motor_brake_mode_e_t);

void driveBackward(double, double, pros::motor_brake_mode_e_t);

void ForwardDrive(double, double, pros::motor_brake_mode_e_t);

void BackwardDrive(double, double, pros::motor_brake_mode_e_t);

// void turnLeft(double, double, pros::motor_brake_mode_e_t);

// void turnRight(double, double, pros::motor_brake_mode_e_t);

void ResetDriveEncoders();