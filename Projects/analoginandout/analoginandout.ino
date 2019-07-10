const int LED = 9;
int value = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(A0);
  analogWrite(LED, value/4);
  delay(10);
}
