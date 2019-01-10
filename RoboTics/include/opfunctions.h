#include "main.h"
#include "motor.h"

void arcadeControl(int powerVertical, int powerHorizontal){
    if(abs(powerVertical) < 20) //If value provided is too small to make the robot move, set it to zero
        powerVertical = 0;
    if(abs(powerHorizontal) < 20)
        powerHorizontal = 0;
    int powerLeft = powerVertical + powerHorizontal; //Power for the left side of drivetrain is vertical plus horizontal
    int powerRight = powerVertical - powerHorizontal; //Power for the right side of drivetrain is vertical minus horizontal
    motorSet(leftBack, powerLeft); //Set motors to desired values
    motorSet(leftFront, powerLeft);
    motorSet(rightBack, powerRight);
    motorSet(rightFront, powerRight);
}

void intakeControl(int stateIn, int stateOut){
    if(stateIn == 1 && stateOut == 0)
        motorSet(intake, 127);
    else if(stateIn == 0 && stateOut == 1)
        motorSet(intake, -127);
    else
        motorSet(intake, 0);
}

void descorerControl(int stateUp, int stateDown){
    if(stateUp == 1 && stateDown == 0)
        motorSet(descorer, 127);
    else if (stateUp == 0 && stateDown == 1)
        motorSet(descorer, -127);
    else
        motorSet(descorer, 0);
}
