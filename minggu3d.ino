#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);   // inisialisasi LCD 16x2
}

void loop() {
  int i;

  // Baris kedua
  lcd.setCursor(0, 1);
  lcd.print("SISTEM TERTANAM");

  // Baris pertama
  lcd.setCursor(0, 0);
  lcd.print("SELAMAT BELAJAR");

  for (i = 0; i < 16; i++) {
    lcd.scrollDisplayRight();   // geser semua isi LCD ke kanan
    delay(800);
  }
}
