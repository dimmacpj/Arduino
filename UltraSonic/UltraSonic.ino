int pina = 4;
int pinb = 5;
int pinc = 6;
int pind = 7;
int pine = 8;
int pinf = 9;
int ping = 10;
int pinh = 11;

int trigger = 3;
int echo = 12;
long distance = 0;
long duration = 0;

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

 pinMode(trigger, OUTPUT);
 pinMode(echo, INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);

  distance = duration / 58;
  Serial.print(distance);
  Serial.println("cm");
  if(distance < 10){
    num(distance);
  }
  delay(500);
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

