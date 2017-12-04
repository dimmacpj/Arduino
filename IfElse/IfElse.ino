int led = 9;
boolean state = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  pinMode(7, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(7) != HIGH){
    if(state == true){
      state = false;
    }else{
      state = true;
    }
    //state = !state;
    digitalWrite(led, state);
    delay(200);
  }else{
    //digitalWrite(led, state);
  }
}
