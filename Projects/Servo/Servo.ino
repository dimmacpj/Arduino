#include <Servo.h>

const int SERVO = 3; // pin for servo
Servo myServo;
const int RESISTOR = 0;
int val = 0;
int angle = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(SERVO);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  val = analogRead(RESISTOR);
  angle = map(val, 0, 1023, 0, 180);
  myServo.write(angle);
  delay(10);

  /*for(angle = 1000; angle < 2000; angle ++){
    myServo.writeMicroseconds(angle);
    Serial.println(angle);
    delay(10);
  }
  
  for(angle = 2000; angle > 1000; angle --){
    myServo.writeMicroseconds(angle);
    Serial.println(angle);
    delay(10);
  }*/
}
