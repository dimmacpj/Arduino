int RXLED = 17;

void setup() {
  // put your setup code here, to run once:
pinMode(RXLED, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Hello World!");
digitalWrite(RXLED,LOW);
TXLED0;
delay(2000);
digitalWrite(RXLED,HIGH);
TXLED1;
delay(500);
}
