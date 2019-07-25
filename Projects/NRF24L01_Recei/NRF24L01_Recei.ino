#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#include <SPI.h>

RF24 radio(2, 10);
const byte address[6] = "00001";
int LED = 13;

void setup() {
  // put your setup code here, to run once:
pinMode(LED, OUTPUT);
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_MIN);
radio.startListening();
}

void loop() {
  // put your main code here, to run repeatedly:
if (radio.available()){
  char text[32] = "";
  radio.read(&text, sizeof(text));
  Serial.println(text);
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
}
}
