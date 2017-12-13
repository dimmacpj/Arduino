#ifndef 28BYJ48Stepper_h
#define 28BYJ48Stepper_h


#include "Arduino.h"

class 28BYJ48Stepper
{
  public:
    //constructors:
    28BYJ48Stepper(int apin, int bpin, int cpin, int dpin);
    //movement setter:
    void setSteps(int total_steps);
    //move speed setter:
    void setSpinSpeed(int spin_speed_phase);
    //step pace setter:
    void setPace(int spin_speed_step);
    //make it moving:
    void move();
  private:
    //motor pin numbers:
    int apin;    //4 phase motor, 4 pins
    int bpin;
    int cpin;
    int dpin;
    void run(int current_phase); //turn on the phase
    int spin_speed_phase;  //time between two phases
    int spin_speed_step;  //time between two steps
    int total_steps;   //total steps the stepper needs to move
    int total_phases;   //total phases the stepper needs; one step
                        //equals eight phases
    int current_phase;  //use this to choose which phase should be on
    int spin_direction;  //spin direction 1/clockwise 0/counterclockwise
}


#endif
