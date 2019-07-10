#ifndef MyStepper_h
#define MyStepper_h

//this is for 28BYJ48-16 stepper
//stride angle: 5.625
//speed variation ratio: 1/16
// number of phase: 4
//this method is using 4-1-2
#include "Arduino.h"

class MyStepper{
  public:
    //constructors:
    MyStepper(int apin, int bpin, int cpin, int dpin);
    //movement setter:
    void setSteps(int total_steps);
    //move speed setter:
    void setSpinSpeed(int spin_speed_phase);
    //step pace setter:
    void setPace(int spin_speed_step);
    //make it moving:
    void makeMove(void);
    int version(void);
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
};


#endif
