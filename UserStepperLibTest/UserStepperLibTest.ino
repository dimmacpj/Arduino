#include <Stepper.h>

Stepper mystepper(200,8,9,10,11);

void setup() {
  // put your setup code here, to run once:
  mystepper.setSpeed(30);
}

void loop() {
  // put your main code here, to run repeatedly:
  mystepper.step(400);
  delay(500);
  mystepper.step(-400);
  delay(500);
}
