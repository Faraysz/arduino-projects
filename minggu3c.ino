#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);   // LCD 16 kolom x 2 baris
}

void loop() {
  int i;

  lcd.setCursor(0, 1);   // kursor di baris kedua (baris pertama = 0, baris kedua = 1)
  lcd.print("SELAMAT BELAJAR SISTEM TERTANAM");
  
  for (i = 0; i < 16; i++) {
    lcd.scrollDisplayRight();   // teks digeser ke kanan
    delay(800);
  }
}
