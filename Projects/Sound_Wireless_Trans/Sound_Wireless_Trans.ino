#include <SPI.h>
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

RF24 radio(2, 10);
int LED = A0;
int soundDetect = A1;
int val = 0;

const byte address[6] = "00001";

void setup() {
  // put your setup code here, to run once:
pinMode(LED, OUTPUT);
pinMode(soundDetect, INPUT);
radio.begin();
radio.openWritingPipe(address);
radio.setPALevel(RF24_PA_MIN);
radio.stopListening();
}

void loop() {
  // put your main code here, to run repeatedly:
val = digitalRead(soundDetect);
const char text[] = "Crying!!!";
if (val == 1) {
  radio.write(&text, sizeof(text));
}
/*
const char text[] = "Crying";
radio.write(&text, sizeof(text));
digitalWrite(LED, HIGH);
delay(500);
digitalWrite(LED, LOW);
delay(1000);
*/
}
