#include "main.h"

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
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_front_mtr(1);
	pros::Motor left_back_mtr(10);
	pros::Motor right_front_mtr(11);
	pros::Motor right_back_mtr(20);
	pros::Motor launcher(4, 5);
	pros::Motor intake(8);
	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);


		if(master.get_digital(DIGITAL_R1) == 1) //button??
			launcher = -75;
		else if(master.get_digital(DIGITAL_R2) == 1)
			launcher = 75;
		else
			launcher= 0;

		if(master.get_digital(DIGITAL_L1) == 1)
			intake = -75;
		else if(master.get_digital(DIGITAL_L2) == 1)
			intake = 75;
		else
			intake = 0;

		left_front_mtr = left;
		left_back_mtr = left;
		right_front_mtr = -right;
		right_back_mtr = -right;
		pros::delay(20);
	}
}
