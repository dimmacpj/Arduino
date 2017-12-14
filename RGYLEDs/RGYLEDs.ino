int pin1 = 3;
int pin2 = 12;
int pin3 = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin3, LOW);
  digitalWrite(pin1, HIGH);
  delay(2000);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  delay(2000);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  delay(2000);
}
