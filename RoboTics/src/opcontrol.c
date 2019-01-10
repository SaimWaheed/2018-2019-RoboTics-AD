#include "main.h"
#include "motor.h"
#include "opfunctions.h"

void operatorControl() {
    while (1) {
        arcadeControl(joystickGetAnalog(1,3), joystickGetAnalog(1,4)); //call for arcade control with left joystick
        intakeControl(joystickGetDigital(1,5,JOY_UP), joystickGetDigital(1,5,JOY_DOWN));
        descorerControl(joystickGetDigital(1,6,JOY_UP), joystickGetDigital(1,6,JOY_DOWN));
        delay(20); //delay to account for sensor refresh rate
    }
}
