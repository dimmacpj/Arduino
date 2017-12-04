/*
long randomR;// brightness for red led
long randomG; // brightness for green led
long randomB; // brightness for blue led
*/
const int LEDR = 9;
const int LEDB = 10;
const int LEDG = 11;
const int BUTTONR = 4;
const int BUTTONB = 5;
const int BUTTONG = 6;
const int BUTTONLIGHT = 7;
int state = 0;
boolean val = false;
boolean old_val = false;
boolean valred = false;
boolean old_valred = false;
boolean valgreen = false;
boolean old_valgreen = false;
boolean valblue = false;
boolean old_valblue =false;
unsigned long startTimeRed = 0;
unsigned long startTimeBlue = 0;
unsigned long startTimeGreen = 0;
int bRed = 128;
int bBlue = 128;
int bGreen = 128;

int checkButtonStatus(boolean value, boolean old_value, int startime, int ledstate, int brightness) {
  if((value == LOW) || (old_value == LOW)){
    if((ledstate == 1) && (millis() - startime > 500)){
      brightness++;
      delay(20);
      if(brightness > 255){
        brightness = 0;
      }
    }
  }
  return brightness;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //randomSeed(analogRead(0));
  pinMode(LEDR, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(BUTTONR, INPUT_PULLUP);
  pinMode(BUTTONB, INPUT_PULLUP);
  pinMode(BUTTONG, INPUT_PULLUP);
  pinMode(BUTTONLIGHT, INPUT_PULLUP);
}

void loop() {

  val = digitalRead(BUTTONLIGHT);
  if((val == LOW) && (old_val == HIGH)){
    state = 1 - state;
    startTimeRed = millis();
    startTimeGreen = millis();
    startTimeBlue = millis();
    delay(200);
  }

  valred = digitalRead(BUTTONR);
  bRed = checkButtonStatus(valred, old_val, startTimeRed, state, bRed);

  valgreen = digitalRead(BUTTONG);
  bGreen = checkButtonStatus(valgreen, old_val, startTimeGreen, state, bGreen);

  valblue = digitalRead(BUTTONB);
  bBlue = checkButtonStatus(valblue, old_val, startTimeBlue, state, bBlue);

  old_val = val;
  if(state == 1){
    analogWrite(LEDR, bRed);
    analogWrite(LEDB, bBlue);
    analogWrite(LEDG, bGreen);
  }else{
    analogWrite(LEDR, 0);
    analogWrite(LEDB, 0);
    analogWrite(LEDG, 0);
  }

  // put your main code here, to run repeatedly:
  /*
  //generate the random brightness
  randomR = random(150,255);
  randomB = random(75);
  randomG = random(75,150);
  //light up
  analogWrite(LEDR, randomR);
  analogWrite(LEDB, randomB);
  analogWrite(LEDG, randomG);
  */
  
  /*
  Serial.print(randomR);
  Serial.print(" + ");
  Serial.print(randomB);
  Serial.print(" + ");
  Serial.println(randomG);
  */
  //delay(1000);

  
}


