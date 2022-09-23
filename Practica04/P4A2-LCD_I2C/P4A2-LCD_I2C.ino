//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int right = 0;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();  
}


void loop()
{
  if(right < 16){
      lcd.scrollDisplayLeft();
      right++;
  }
  lcd.setCursor(16,0);
  lcd.print("Yohaly");
  lcd.setCursor(16,1);
  lcd.print("Bruno");
  delay(500);
}
