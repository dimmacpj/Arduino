const int LED = 11;
const int PIR = 3;
int val = 0;
int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(PIR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(PIR);
  if(val == 1){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
}
