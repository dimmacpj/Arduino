const int LED = 5; // pin for led
const int INFRARED = 9; //pin for infrared
boolean state = true; //state of infrared receiver

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(INFRARED, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(INFRARED);
  if(state == HIGH){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
}
