//#include <Stepper.h>


int apin = 8;
int bpin = 9;
int cpin = 10;
int dpin = 11;


//Stepper mystepper(512,8,9,10,11);

void setup() {
  // put your setup code here, to run once:
  //mystepper.setSpeed(512);
  
  pinMode(apin, OUTPUT);
  pinMode(bpin, OUTPUT);
  pinMode(cpin, OUTPUT);
  pinMode(dpin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //singlePhrase();

  single();
  delay(1);
  
  twofour();
  delay(1);

  twoeight();
  delay(1);
  /*
  mystepper.step(512);
  delay(500);
  mystepper.step(-512);
  delay(500);
  */
}

void twoeight(){
  digitalWrite(dpin,LOW);
  digitalWrite(apin,HIGH);//a
  delay(1);
  digitalWrite(bpin,HIGH);//ab
  delay(1);
  digitalWrite(apin,LOW);//b
  delay(1);
  digitalWrite(cpin,HIGH);//bc
  delay(1);
  digitalWrite(bpin,LOW);//c
  delay(1);
  digitalWrite(dpin,HIGH);//cd
  delay(1);
  digitalWrite(cpin,LOW);//d
  delay(1);
  digitalWrite(apin,HIGH);//da
  delay(1);
  
}

void twofour(){
  digitalWrite(dpin,LOW);
  digitalWrite(apin,HIGH);
  digitalWrite(bpin,HIGH);//AB
  delay(10);
  digitalWrite(apin,LOW);
  digitalWrite(cpin,HIGH);//BC
  delay(10);
  digitalWrite(bpin,LOW);
  digitalWrite(dpin,HIGH);//CD
  delay(10);
  digitalWrite(cpin,LOW);
  digitalWrite(apin,HIGH);//DA
  delay(10);
  
}

void single(){
  digitalWrite(dpin,LOW);
  digitalWrite(apin, HIGH);
  delay(10);
  digitalWrite(apin,LOW);
  digitalWrite(bpin, HIGH);
  delay(10);
  digitalWrite(bpin,LOW);
  digitalWrite(cpin, HIGH);
  delay(10);
  digitalWrite(cpin,LOW);
  digitalWrite(dpin, HIGH);
  delay(10);
}

void singlePhrase(){
  for(int i = 0 ; i < 64 ; i ++){
    digitalWrite(dpin,LOW);
    digitalWrite(cpin, HIGH);
    delay(10);
    digitalWrite(cpin,LOW);
    digitalWrite(bpin, HIGH);
    delay(10);
    digitalWrite(bpin,LOW);
    digitalWrite(apin, HIGH);
    delay(10);
    digitalWrite(apin,LOW);
    digitalWrite(dpin, HIGH);
    delay(10);
  }
  
  delay(500);

  for(int i = 0 ; i < 64 ; i ++){
    digitalWrite(dpin,LOW);
    digitalWrite(apin, HIGH);
    delay(10);
    digitalWrite(apin,LOW);
    digitalWrite(bpin, HIGH);
    delay(10);
    digitalWrite(bpin,LOW);
    digitalWrite(cpin, HIGH);
    delay(10);
    digitalWrite(cpin,LOW);
    digitalWrite(dpin, HIGH);
    delay(10);
  }

  delay(500);
}

