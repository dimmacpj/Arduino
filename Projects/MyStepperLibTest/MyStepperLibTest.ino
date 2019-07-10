#include <MyStepper.h>


MyStepper mystepper1(8, 9, 10, 11);

void setup() {
  // put your setup code here, to run once:
  mystepper1.setSpinSpeed(1);
  mystepper1.setPace(1);
  mystepper1.setSteps(128);
}

void loop() {
  // put your main code here, to run repeatedly:
  mystepper1.makeMove();
  delay(1000);
}
