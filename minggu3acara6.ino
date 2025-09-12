#include <LiquidCrystal.h>  

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

void setup() {  
  lcd.begin(20, 4);  
}  

void loop() {  
  int i;  

  lcd.setCursor(0, 0);  
  lcd.print("SELAMAT BELAJAR SISTEM TERTANAM");  

  for (i = 0; i < 16; i++) {  
    lcd.scrollDisplayLeft();  
    delay(400);  
  }  
}  
