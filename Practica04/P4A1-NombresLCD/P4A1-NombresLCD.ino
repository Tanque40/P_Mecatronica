#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int right = 0;

void setup() {
    lcd.begin(16, 2);
}

void loop() {
    if(right < 10){
      lcd.scrollDisplayRight();
      right++;
    }
    lcd.setCursor(0, 0);
    lcd.print("Wohaly");
    lcd.setCursor(0, 1);
    lcd.print("Bruno");
    delay(500);
}
