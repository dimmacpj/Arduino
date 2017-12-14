int led = 9;
int pir = 7;
boolean val = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT_PULLUP);

  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(pir);
  if(val == false){
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
  }
}
