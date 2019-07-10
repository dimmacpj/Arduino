#include "Arduino.h"
#include "28BYJ48Stepper.h"

//constructors:
28BYJ48Stepper::28BYJ48Stepper(int apin, int bpin, int cpin, int dpin){
  this->apin = apin;
  this->bpin = bpin;
  this->cpin = cpin;
  this->dpin = dpin;
  //initial pins:
  pinMode(apin, OUTPUT);
  pinMode(bpin, OUTPUT);
  pinMode(cpin, OUTPUT);
  pinMode(dpin, OUTPUT);

  this->spin_direction = 0;
  this->spin_speed_phase = 0;
  this->spin_speed_step = 0;
  this->total_steps = 0;
  this->total_phases = this->total_steps * 8;
  this->current_phase = 0;
}

//movement setter:
void 28BYJ48Stepper::setSteps(int total_steps){
  this->total_steps = total_steps;// total steps needs to move.
  this->total_phases = abs(this->total_steps) * 8; // total phase need to be on, one step equals eight phases.
  //change direction
  if(this->total_steps > 0){
    this->spin_direction = 1;
  }else{
    this->spin_direction = 0;
  }
}

//move speed setter:
void 28BYJ48Stepper::setSpinSpeed(int spin_speed_phase){
  this->spin_speed_phase = spin_speed_phase;
}

//step pace setter:
void 28BYJ48Stepper::setPace(int spin_speed_step){
  this->spin_speed_step = spin_speed_step;
}

//make it moving:
void 28BYJ48Stepper::move(){
  //start spinning
  while(this->total_phases > 0){
    //stop some time every 8 phase movements
    if(this->current_phase % 8 == 0){
      delay(this->spin_speed_step);//also meas stop some time every step.
    }
    if(this->spin_direction == 1){
      run(this->current_phase % 8);
      this->current_phase++;
      if(this->current_phase == 1024){//reset current phase to 0 once it reach 1024, one revolution needs 1024 phase movement.
        this->current_phase = 0;
      }
    }else if(this->spin_direction == 0){
      if(this->current_phase == 0){
        this->current_phase = 1024;
      }
      run(this->current_phase % 8);
      this->current_phase--;
    }
    delay(this->spin_speed_phase);
    this->total_phases--;
  }
}

//turn on the phase:
void 28BYJ48Stepper::run(int current_phase){
  switch (current_phase) {
    case 0:
      digitalWrite(dpin,LOW);
      digitalWrite(apin,HIGH);//a
      break;
    case 1:
      digitalWrite(bpin,HIGH);//ab
      break;
    case 2:
      digitalWrite(apin,LOW);//b
      break;
    case 3:
      digitalWrite(cpin,HIGH);//bc
      break;
    case 4:
      digitalWrite(bpin,LOW);//c
      break;
    case 5:
      digitalWrite(dpin,HIGH);//cd
      break;
    case 6:
      digitalWrite(cpin,LOW);//d
      break;
    case 7:
      digitalWrite(apin,HIGH);//da
      break;
    default:
      digitalWrite(apin,LOW);
      digitalWrite(bpin,LOW);
      digitalWrite(cpin,LOW);
      digitalWrite(dpin,LOW);
      break;
  }
}
