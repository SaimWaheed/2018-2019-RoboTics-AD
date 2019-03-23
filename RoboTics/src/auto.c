#include "main.h"


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
#include "okapi/api.hpp"
using namespace okapi;

okapi:: MotorGroup right({11, 20});
okapi:: MotorGroup left({1, 10});

const auto WHEEL_DIAMETER = 4.25_in;
const auto CHASSIS_WIDTH = 13.5_in;

pros::Motor launcher(4,5);
pros::Motor intake(8);

auto chassis = ChassisControllerFactory::create(
  left, right,
  AbstractMotor::gearset::green,
  {WHEEL_DIAMETER, CHASSIS_WIDTH}
);

/* intake
void intake(double msec){
intake.moveVelocity(200);
delay(msec);
intake.moveVelocity(0);
}
*/

/*
float speedChangePerLoop = 0.06;

float leftPower = 0, rightPower = 0;

void accelerateDrive(int leftTargetPower, int rightTargetPower)
{
	if(leftTargetPower < leftPower)
	{
		leftPower -= speedChangePerLoop;
    chassis.setMaxVelocity(leftPower);
	}
	else if(leftTargetPower > leftPower)
	{
		leftPower += speedChangePerLoop;
    chassis.setMaxVelocity(leftPower);
	}
	else{}

	if(rightTargetPower < rightPower)
	{
		rightPower -= speedChangePerLoop;
    chassis.setMaxVelocity(rightPower);
	}
	else if(rightTargetPower > rightPower)
	{
		rightPower += speedChangePerLoop;
    chassis.setMaxVelocity(rightPower);
	}
	else{}

}
*/

//auto PID = IterativePosPIDController::create(double ikP, double ikI, double ikD);

void autonomous() {
  right.setReversed(true);
  //accelerateDrive(100, 100);
  //chassis.moveDistance(1_ft);

  chassis.setMaxVelocity(125);
  chassis.moveDistance(1_ft); //moves in position to shoot
  intake = -75;
  pros::delay(500);
  chassis.moveDistance(2.6_ft); //moves forward to hit the bottom flag
  chassis.moveDistance(-3.6_ft); //moves backward to the starting position
  chassis.turnAngle(-90_deg); //turns toward the cap
  intake = 100;
  pros::delay(1000);
  chassis.moveDistance(2.6_ft); //move forward to take the ball


}
