#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <LiquidCrystal.h>
#include <SPI.h>

LiquidCrystal lcd(9, 8, 4, 5, 6, 7);
RF24 radio(2, 10);
const byte address[6] = "00001";
int LED = A0;

void setup() {
  // put your setup code here, to run once:
pinMode(LED, OUTPUT);
Serial.begin(9600);
lcd.begin(16, 2);
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
  lcd.setCursor(0, 0);
  lcd.print(text);
  delay(50);
}
else {
  digitalWrite(LED, LOW);
  Serial.println("Nothing");
  lcd.setCursor(0, 0);
  lcd.print("Sleeping!");
  delay(50);
}
delay(150);
}
