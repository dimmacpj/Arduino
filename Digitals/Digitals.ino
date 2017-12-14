int pina = 4;
int pinb = 5;
int pinc = 6;
int pind = 7;
int pine = 8;
int pinf = 9;
int ping = 10;
int pinh = 11;
int randomNum;

void setup() {
  // put your setup code here, to run once:
 pinMode(pina, OUTPUT);
 pinMode(pinb, OUTPUT);
 pinMode(pinc, OUTPUT);
 pinMode(pind, OUTPUT);
 pinMode(pine, OUTPUT);
 pinMode(pinf, OUTPUT);
 pinMode(ping, OUTPUT);
 pinMode(pinh, OUTPUT);
 randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  num(5);
  delay(2000);
  num(22);
  delay(1000);
  num(2);
  delay(2000);
  num(22);
  delay(1000);
  num(0);
  delay(2000);
  num(22);
  delay(1000);
  */
  randomNum = random(10);
  num(randomNum);
  delay(2000);
}

void num(int num){
  switch(num){
    case 0:
      digitalWrite(pina, LOW);
      digitalWrite(pinb, LOW);
      digitalWrite(pinc, LOW);
      digitalWrite(pind, LOW);
      digitalWrite(pine, LOW);
      digitalWrite(pinf, LOW);
      digitalWrite(ping, HIGH);
      digitalWrite(pinh, HIGH);
      break;
    case 1:
      digitalWrite(pina, HIGH);
      digitalWrite(pinb, LOW);
      digitalWrite(pinc, LOW);
      digitalWrite(pind, HIGH);
      digitalWrite(pine, HIGH);
      digitalWrite(pinf, HIGH);
      digitalWrite(ping, HIGH);
      digitalWrite(pinh, HIGH);
      break;
    case 2:
      digitalWrite(pina, LOW);
      digitalWrite(pinb, LOW);
      digitalWrite(pinc, HIGH);
      digitalWrite(pind, LOW);
      digitalWrite(pine, LOW);
      digitalWrite(pinf, HIGH);
      digitalWrite(ping, LOW);
      digitalWrite(pinh, HIGH);
      break;
    case 3:
      digitalWrite(pina, LOW);
      digitalWrite(pinb, LOW);
      digitalWrite(pinc, LOW);
      digitalWrite(pind, LOW);
      digitalWrite(pine, HIGH);
      digitalWrite(pinf, HIGH);
      digitalWrite(ping, LOW);
      digitalWrite(pinh, HIGH);
      break;
    case 4:
      digitalWrite(pina, HIGH);
      digitalWrite(pinb, LOW);
      digitalWrite(pinc, LOW);
      digitalWrite(pind, HIGH);
      digitalWrite(pine, HIGH);
      digitalWrite(pinf, LOW);
      digitalWrite(ping, LOW);
      digitalWrite(pinh, HIGH);
      break;
    case 5:
      digitalWrite(pina, LOW);
      digitalWrite(pinb, HIGH);
      digitalWrite(pinc, LOW);
      digitalWrite(pind, LOW);
      digitalWrite(pine, HIGH);
      digitalWrite(pinf, LOW);
      digitalWrite(ping, LOW);
      digitalWrite(pinh, HIGH);
      break;
    case 6:
      digitalWrite(pina, LOW);
      digitalWrite(pinb, HIGH);
      digitalWrite(pinc, LOW);
      digitalWrite(pind, LOW);
      digitalWrite(pine, LOW);
      digitalWrite(pinf, LOW);
      digitalWrite(ping, LOW);
      digitalWrite(pinh, HIGH);
      break;
    case 7:
      digitalWrite(pina, LOW);
      digitalWrite(pinb, LOW);
      digitalWrite(pinc, LOW);
      digitalWrite(pind, HIGH);
      digitalWrite(pine, HIGH);
      digitalWrite(pinf, HIGH);
      digitalWrite(ping, HIGH);
      digitalWrite(pinh, HIGH);
      break;
    case 8:
      digitalWrite(pina, LOW);
      digitalWrite(pinb, LOW);
      digitalWrite(pinc, LOW);
      digitalWrite(pind, LOW);
      digitalWrite(pine, LOW);
      digitalWrite(pinf, LOW);
      digitalWrite(ping, LOW);
      digitalWrite(pinh, HIGH);
      break;
    case 9:
      digitalWrite(pina, LOW);
      digitalWrite(pinb, LOW);
      digitalWrite(pinc, LOW);
      digitalWrite(pind, HIGH);
      digitalWrite(pine, HIGH);
      digitalWrite(pinf, LOW);
      digitalWrite(ping, LOW);
      digitalWrite(pinh, HIGH);
      break;
    default:
      digitalWrite(pina, HIGH);
      digitalWrite(pinb, HIGH);
      digitalWrite(pinc, HIGH);
      digitalWrite(pind, HIGH);
      digitalWrite(pine, HIGH);
      digitalWrite(pinf, HIGH);
      digitalWrite(ping, HIGH);
      digitalWrite(pinh, HIGH);
      break;
  }
}

