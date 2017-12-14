const unsigned char DM[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
const int LEDS = 8;
int pins[8] = {5,4,9,10,11,6,7,8};


void setup() {
  // put your setup code here, to run once:
  for(int thisPin = 0; thisPin < LEDS; thisPin++){
    pinMode(pins[thisPin], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 10; i++){
    deal(DM[i]);
    delay(1000);
  }
}

void deal(unsigned char value){
  for(int i = 0; i < 8; i++){
    digitalWrite(pins[i], bitRead(value, i)); 
  }
}

