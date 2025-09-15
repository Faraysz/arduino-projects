int pinLed[] = {6, 9, 10, 11};  // Array LED (4 LED)

void setup() {
  // Atur semua pin LED sebagai OUTPUT
  for (int i = 0; i < 4; i++) {
    pinMode(pinLed[i], OUTPUT);
  }

  Serial.begin(9600);
  Serial.println("Masukkan 3 --> nyalakan semua LED");
  Serial.println("Masukkan 4 --> matikan semua LED");
}

void loop() {
  if (Serial.available()) {
    int kondisi = Serial.parseInt();

    if (kondisi == 3) {
      // Nyalakan semua LED
      for (int i = 0; i < 4; i++) {
        digitalWrite(pinLed[i], HIGH);
      }
      Serial.println("SEMUA LED MENYALA");
    }

    if (kondisi == 4) {
      // Matikan semua LED
      for (int i = 0; i < 4; i++) {
        digitalWrite(pinLed[i], LOW);
      }
      Serial.println("SEMUA LED PADAM");
    }
  }
}
