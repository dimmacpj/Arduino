#include <LiquidCrystal.h>

LiquidCrystal lcd(3, 5, 11, 10, 9, 8);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("I Love U Rayna!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
