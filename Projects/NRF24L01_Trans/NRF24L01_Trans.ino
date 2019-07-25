#include <SPI.h>
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

RF24 radio(2, 10);
int LED = 13;

const byte address[6] = "00001";

void setup() {
  // put your setup code here, to run once:
pinMode(LED, OUTPUT);
radio.begin();
radio.openWritingPipe(address);
radio.setPALevel(RF24_PA_MIN);
radio.stopListening();
}

void loop() {
  // put your main code here, to run repeatedly:
const char text[] = "Hello";
radio.write(&text, sizeof(text));
digitalWrite(LED, HIGH);
delay(500);
digitalWrite(LED, LOW);
delay(1000);
}
