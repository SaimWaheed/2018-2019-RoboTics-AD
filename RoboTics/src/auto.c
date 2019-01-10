#include "motor.h"
#include "API.h"
#include "main.h"

double inchToTick(double inches) {
  double inchesPerRotation = 4.25 * 3.14159265;
  double ticks = (inches/inchesPerRotation) * 360;
  return ticks;
}

/*
double PID(int requestedVal, Encoder encoder, double kp, double ki, double kd){
  double integral = 0;
  double derivative = 0;
  double previousErr = 0;
  double power = 0;
  double ticks = 0;

 while(ticks <= requestedVal){
          double error = requestedVal - ticks;
          integral += error/50;
          derivative = (error - previousErr)*50;
          previousErr = error;
          power = error*kp + integral*ki + derivative*kd;
          delay(20);
          ticks = encoderGet(encoder);
      }
      if(integral >= 10000)
        integral = 4000; //These are soft maximums for testing
      if(ticks >= requestedVal){
          integral = 0;
          power = 0;
        }
          return power;
}
*/

double Proportion(int requestedVal, Encoder encoder, double kp){
  double integral = 0;
  double derivative = 0;
  double previousErr = 0;
  double power = 0;
  double ticks = 0;
  double error = requestedVal - ticks;
  power = error*kp;
  if(power > 80)
    power = 80;
  return power;
}

void Adrive (int ltocks, int rtocks, Encoder lEncoder, Encoder rEncoder) {
  motorSet(leftBack, Proportion(inchToTick(ltocks), lEncoder, .25));
  motorSet(leftFront, Proportion(inchToTick(ltocks), lEncoder, .25));
  motorSet(rightBack, Proportion(inchToTick(ltocks), lEncoder, .25));
  motorSet(rightFront, Proportion(inchToTick(ltocks), lEncoder, .25));
}

void Alaunch() {
		motorSet(launcher, -127);
    delay(1000);
}
