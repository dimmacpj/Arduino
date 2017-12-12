const int RESISTOR = 0; // pin for 10k resistor
const int LED = 3; //pin for led
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(RESISTOR);

  analogWrite(LED, val/4);
  Serial.println(val/4);
  delay(10);
}
