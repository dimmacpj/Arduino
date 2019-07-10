int apin = 8;
int bpin = 9;
int cpin = 10;
int dpin = 11;

int _step = 0;

boolean dir = true;

int stepperspeed = 1;

void setup(){
  pinMode(apin, OUTPUT);
  pinMode(bpin, OUTPUT);
  pinMode(cpin, OUTPUT);
  pinMode(dpin, OUTPUT);
}

void loop(){
  switch(_step){
    case 0:
      digitalWrite(apin, HIGH);
      digitalWrite(bpin, LOW);
      digitalWrite(cpin, LOW);
      digitalWrite(dpin, LOW);
      break;
    case 1:
      digitalWrite(apin, HIGH);
      digitalWrite(bpin, HIGH);
      digitalWrite(cpin, LOW);
      digitalWrite(dpin, LOW);
      break;
    case 2:
      digitalWrite(apin, LOW);
      digitalWrite(bpin, HIGH);
      digitalWrite(cpin, LOW);
      digitalWrite(dpin, LOW);
      break;
    case 3:
      digitalWrite(apin, LOW);
      digitalWrite(bpin, HIGH);
      digitalWrite(cpin, HIGH);
      digitalWrite(dpin, LOW);
      break;
    case 4:
      digitalWrite(apin, LOW);
      digitalWrite(bpin, LOW);
      digitalWrite(cpin, HIGH);
      digitalWrite(dpin, LOW);
      break;
    case 5:
      digitalWrite(apin, LOW);
      digitalWrite(bpin, LOW);
      digitalWrite(cpin, HIGH);
      digitalWrite(dpin, HIGH);
      break;
    case 6:
      digitalWrite(apin, LOW);
      digitalWrite(bpin, LOW);
      digitalWrite(cpin, LOW);
      digitalWrite(dpin, HIGH);
      break;
    case 7:
      digitalWrite(apin, HIGH);
      digitalWrite(bpin, LOW);
      digitalWrite(cpin, LOW);
      digitalWrite(dpin, HIGH);
      break;
    default:
      digitalWrite(apin, LOW);
      digitalWrite(bpin, LOW);
      digitalWrite(cpin, LOW);
      digitalWrite(dpin, LOW);
      break;
  }

  if(dir){
    _step++;
  }else{
    _step--;
  }
  if(_step > 7){
    _step = 0;
  }
  if(_step < 0){
    _step = 7;
  }
  delay(stepperspeed);
}

