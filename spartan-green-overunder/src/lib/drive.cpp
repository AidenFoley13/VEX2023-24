#include "drive.h"

void ResetDriveEncoders() {
    frontLeft.tare_position();
    frontRight.tare_position();
    backRight.tare_position();
    backLeft.tare_position();
}

void brake(pros::motor_brake_mode_e_t brakeMode = pros::E_MOTOR_BRAKE_COAST)
{
    frontRight.set_brake_mode(brakeMode);
	frontLeft.set_brake_mode(brakeMode);
	backRight.set_brake_mode(brakeMode);
	backLeft.set_brake_mode(brakeMode);
	frontRight.brake();
	frontLeft.brake();
	backRight.brake();
	backLeft.brake();
}

// void turnRight(double targetAngle, double power=.25, pros::motor_brake_mode_e_t brakeMode=pros::E_MOTOR_BRAKE_COAST) {
// 	while (inertial.get_rotation() < targetAngle - 2 || inertial.get_rotation() > targetAngle + 2) {
// 		frontRight.move_relative(targetAngle, -power*200); // power is the percentage of power out of a 200 rpm motor
// 		frontLeft.move_relative(targetAngle, power*200);
// 		backRight.move_relative(targetAngle, -power*200);
// 		backLeft.move_relative(targetAngle, power*200);
// 	}
// 	brake(brakeMode);
// }

// void turnLeft(double targetAngle, double power=.25, pros::motor_brake_mode_e_t brakeMode=pros::E_MOTOR_BRAKE_COAST) {
// 	while (inertial.get_rotation() < targetAngle - 2 || inertial.get_rotation() > targetAngle + 2) {
// 		frontRight.move_relative(targetAngle, power*200); // power is the percentage of power out of a 200 rpm motor
// 		frontLeft.move_relative(targetAngle, -power*200);
// 		backRight.move_relative(targetAngle, power*200);
// 		backLeft.move_relative(targetAngle, -power*200);
// 	}
// 	brake(brakeMode);
// }

void driveBackward(double targetDistance, double power, pros::motor_brake_mode_e_t brakeMode=pros::E_MOTOR_BRAKE_COAST) {
		frontRight.move_relative(targetDistance, -power*200); // power is the percentage of power out of a 200 rpm motor
		frontLeft.move_relative(targetDistance, -power*200);
		backRight.move_relative(targetDistance, -power*200);
		backLeft.move_relative(targetDistance, -power*200);
		brake(brakeMode);
}

void ForwardDrive(double targetDistance, double power=1, pros::motor_brake_mode_e_t brakeMode=pros::E_MOTOR_BRAKE_COAST) {
    while( backLeft.get_position() < targetDistance && backRight.get_position() < targetDistance) {
        frontRight.move_velocity(600*power); // power is the percentage of power out of a 600 rpm motor
        frontLeft.move_velocity(600*power);
        backRight.move_velocity(600*power);
        backLeft.move_velocity(600*power);
    }
    brake(brakeMode);
    pros::delay(200);
}

void BackwardDrive(double targetDistance, double power=1, pros::motor_brake_mode_e_t brakeMode=pros::E_MOTOR_BRAKE_COAST) {
    while( backLeft.get_position() > -targetDistance && backRight.get_position() > -targetDistance) {
        frontRight.move_velocity(-600*power); // power is the percentage of power out of a 600 rpm motor
        frontLeft.move_velocity(-600*power);
        backRight.move_velocity(-600*power);
        backLeft.move_velocity(-600*power);
    }
    brake(brakeMode);
    pros::delay(200);
}