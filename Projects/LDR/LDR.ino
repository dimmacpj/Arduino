const int LED = 9;
const int BUTTON = 7;
boolean state = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(BUTTON);
  if(state == LOW){
    digitalWrite(LED, HIGH);
    delay(200);
  }else{
    digitalWrite(LED, LOW);
  }
}
