#include "main.h"
#include "./lib/drive.h"

#define CATA_RIGHT_PORT 10
#define CATA_LEFT_PORT 1
#define INTAKE_PORT 15

using pros::Motor;

pros::Controller con(pros::E_CONTROLLER_MASTER);
pros::Motor cataRight(CATA_RIGHT_PORT, MOTOR_GEAR_GREEN);
pros::Motor cataLeft(CATA_LEFT_PORT, MOTOR_GEAR_GREEN, true);
pros::Motor intake(INTAKE_PORT, MOTOR_GEAR_GREEN);
// pros::Motor roller(ROLLER_PORT, MOTOR_GEAR_GREEN);

// pros::ADIDigitalOut endgame (PNEUMATIC_ENDGAME);

// pros::Imu inertial(INERTIAL_PORT);
// pros::Optical optical(OPTICAL_PORT);
// pros::GPS gps(GPS_PORT);
// pros::ADIDigitalIn limitSwitch(LIMIT_SWITCH_PORT);

bool cataLimit = false;
bool disableAutoCata = false;
int invertRoller = -1;

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

int GetGearsetRPM(const Motor& m) {
	if( m.get_gearing() == MOTOR_GEAR_BLUE ) { return 600; }
	else if( m.get_gearing() == MOTOR_GEAR_GREEN ) { return 200; }
	else { return 100; }
}

void movePID(const Motor& control_motor, const int& target_velocity_pct, const int & time_ms) {
	int pwr_cntrl = 127;
	int time_interval = 100;
	int interval_cnt = time_ms/ time_interval;
	int target_velocity = target_velocity_pct*(GetGearsetRPM(control_motor));
	while( interval_cnt ) {
		control_motor.move(pwr_cntrl);
		if( control_motor.get_actual_velocity() < target_velocity ) {
			if( pwr_cntrl < 127) pwr_cntrl ++;
		} else { pwr_cntrl --; }
		pros::delay(time_interval);
		interval_cnt --;
	}
	control_motor.brake();
}

// void shoot() {
// 	cataLeft.move_velocity(100);
// 	cataRight.move_velocity(100);
// 	pros::delay(250);
// 	while( !limitSwitch.get_value() ) {
// 		cataLeft.move_velocity(100);
// 		cataRight.move_velocity(100);
// 	}
// 	cataLeft.move_velocity(0);
// 	cataRight.move_velocity(0);
// }


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	// pros::lcd::initialize();
	// pros::lcd::set_text(1, "Hello PROS User!");

	// pros::lcd::register_btn1_cb(on_center_button);
	//gps.initialize_full(X_INITIAL, Y_INITIAL, HEADING_INITIAL, X_OFFSET, Y_OFFSET);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	// inertial.reset();
	//gps.initialize_full(X_INITIAL, Y_INITIAL, HEADING_INITIAL, X_OFFSET, Y_OFFSET);
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	/*roller.move_velocity(-100);
	pros::delay(1000);
    frontLeft.move_velocity(200);
    backLeft.move_velocity(200);
    frontRight.move_velocity(200);
    backRight.move_velocity(200);
    pros::delay(250);
    brake(pros::E_MOTOR_BRAKE_COAST);
	pros::delay(500);
    roller.brake();
    frontLeft.move_velocity(-200);
    backLeft.move_velocity(-200);
    frontRight.move_velocity(-200);
    backRight.move_velocity(-200);
	pros::delay(115);
	brake();
	pros::delay(1000);
	frontLeft.move_velocity(100);
    backLeft.move_velocity(100);
    frontRight.move_velocity(-100);
    backRight.move_velocity(-100);
	pros::delay(750);
	brake(pros::E_MOTOR_BRAKE_COAST);
	pros::delay(500);
	shoot();*/

	// roller.move_velocity(-20);
	// pros::delay(1000);
    // frontLeft.move_velocity(200);
    // backLeft.move_velocity(200);
    // frontRight.move_velocity(200);
    // backRight.move_velocity(200);
    // pros::delay(250);
    // brake(pros::E_MOTOR_BRAKE_COAST);
	// pros::delay(500);
    // roller.brake();
    // frontLeft.move_velocity(-200);
    // backLeft.move_velocity(-200);
    // frontRight.move_velocity(-200);
    // backRight.move_velocity(-200);
	// pros::delay(205);
	// brake();
	// pros::delay(1000);
	// frontLeft.move_velocity(50);
    // backLeft.move_velocity(50);
    // frontRight.move_velocity(-50);
    // backRight.move_velocity(-50);
	// pros::delay(1000);
	// brake();
	// pros::delay(500);
	// frontLeft.move_velocity(-100);
    // backLeft.move_velocity(-100);
    // frontRight.move_velocity(-100);
    // backRight.move_velocity(-100);
	// pros::delay(4900);
	// brake();
	// frontLeft.move_velocity(-50);
    // backLeft.move_velocity(-50);
    // frontRight.move_velocity(50);
    // backRight.move_velocity(50);
	// pros::delay(1650);
	// brake();
	// pros::delay(1500);
	// frontLeft.move_velocity(-100);
    // backLeft.move_velocity(-100);
    // frontRight.move_velocity(-100);
    // backRight.move_velocity(-100);
	// pros::delay(850);
	// brake();
	// shoot();
	// intake.move(127);
	// pros::delay(1000);
	// shoot();
	// intake.move(0);

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	// optical.set_led_pwm(100);
	//gps.initialize_full(X_OFFSET, Y_OFFSET, X_INITIAL, Y_INITIAL, HEADING_INITIAL);
	while (true) {
		// pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		//                  (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		//                  (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

		// tank code
		frontLeft.move(con.get_analog(ANALOG_LEFT_Y));
		backLeft.move(con.get_analog(ANALOG_LEFT_Y));
		middleLeft.move(con.get_analog(ANALOG_LEFT_Y));
		frontRight.move(con.get_analog(ANALOG_RIGHT_Y));
		backRight.move(con.get_analog(ANALOG_RIGHT_Y));
		middleRight.move(con.get_analog(ANALOG_RIGHT_Y));


		// arcade code
		// int power = con.get_analog(ANALOG_LEFT_Y);
		// int turn = con.get_analog(ANALOG_RIGHT_X);

		// int left = power + turn;
		// int right = power - turn;

		// frontLeft.move(left);
		// backLeft.move(left);
		// frontRight.move(right);
		// backRight.move(right);
		//roller.move(50);
		
		// if ( con.get_digital(DIGITAL_Y) ) {
		// 	roller.move(50);
		// }

		// if (con.get_digital(DIGITAL_R1)) {
		// 	cataLimit = false;
		// 	cataLeft.move_velocity(200); // 200 rpm 
		// 	cataRight.move_velocity(200);
		// } else if (!limitSwitch.get_value() && !cataLimit && !disableAutoCata) {
		// 	cataLeft.move_velocity(100);
		// 	cataRight.move_velocity(100);
		// } else {
		// 	cataLimit = true;
		// 	cataLeft.move_velocity(0);
		// 	cataRight.move_velocity(0);
		// }

		if (con.get_digital(DIGITAL_X)) {
			disableAutoCata = true;
		} else if (con.get_digital(DIGITAL_Y)) {
			disableAutoCata = false;
		}

		// if (con.get_digital(DIGITAL_R2)) {
		// 	roller.move_velocity(invertRoller*200); // 200 rpm
		// } else {
		// 	roller.move_velocity(0);
		// }

		if (con.get_digital(DIGITAL_L1)) {
			intake.move_velocity(200); // 60% of 200 rpm
		} else if (con.get_digital(DIGITAL_L2)) {
			intake.move_velocity(200);
		} else {
			intake.move_velocity(0);
		}

		if (con.get_digital(DIGITAL_LEFT) && invertRoller == 1) {
			invertRoller = -1;
			pros::delay(100);
		} else if (con.get_digital(DIGITAL_LEFT) && invertRoller == -1) {
			invertRoller = 1;
			pros::delay(100);
		}


		// if (con.get_digital(DIGITAL_A)) {
		// 	endgame.set_value(true);
		// } else if (con.get_digital(DIGITAL_B)) {
		// 	endgame.set_value(false);
		// }
		
		// double heading = gps.get_heading();
		// pros::c::gps_status_s_t status = gps.get_status();
        // pros::screen::print(TEXT_MEDIUM, 1, "Rotation: %3f", heading);
        // pros::screen::print(TEXT_MEDIUM, 2, "x: %3f, y: %3f, pitch: %3f", status.x, status.y);
        // pros::screen::print(TEXT_MEDIUM, 3, "yaw: %3f, roll: %3f", status.pitch, status.yaw);
        // pros::screen::print(TEXT_MEDIUM, 4, "roll: %3f", status.roll);
		// pros::delay(20);
		
	}
}