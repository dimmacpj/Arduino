const int MOTOR = 9;//pin for motor
const int RES = 0; //pin for resistor
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(RES);
  analogWrite(MOTOR, val/4);
  //digitalWrite(MOTOR, HIGH);
  delay(10);
}
