int LED = A0;
//int soundSensorA = A0;
int soundSensorD = A1;
int val = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(LED, OUTPUT);
pinMode(soundSensorD, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
val = digitalRead(soundSensorD);
if (val == 1){
  digitalWrite(LED, HIGH);
  Serial.println(val);
  //delay(1000);
}
else {
  digitalWrite(LED, LOW);
  Serial.println(val);
}
}
