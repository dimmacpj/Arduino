int led = 12;
int pir = 3;

void setup() {
  // put your setup code here, to run once:
  
  //pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
  Serial.begin(9600);
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(pir);
  Serial.println(val);
  if(val == 1){
    Serial.println(val);
    tone(led, 131);
    //digitalWrite(led, HIGH);
  }else{
    //digitalWrite(led, LOW);
    noTone(led);
  }
}
