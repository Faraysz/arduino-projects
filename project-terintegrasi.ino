  // Pin Konfigurasi
int ledPins[] = {6, 9, 10, 11};   // 4 LED
int buzzer = 12;                 // Buzzer
int button = 3;                 // Pushbutton

void setup() {
  // Set LED dan buzzer sebagai OUTPUT
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);   // button aktif low

  Serial.begin(9600);
  Serial.println("Tekan tombol untuk menampilkan menu...");
}

void loop() {
  // Jika tombol ditekan, tampilkan menu di Serial Monitor
  if (digitalRead(button) == LOW) {
    delay(200); // debounce
    tampilkanMenu();
  }

  // Jika ada input dari Serial Monitor
  if (Serial.available()) {
    int pilihan = Serial.parseInt();

    if (pilihan == 1) {
      ledKelapKelip();
    } else if (pilihan == 2) {
      buzzerSirine();
    } else if (pilihan == 3) {
      lampuBerjalan();
    } else if (pilihan == 4) {
      pwmFadeLed();
    } else {
      Serial.println("Program selesai, monggo dipilih lagi");
    }
  }
}

// ---------------- Fungsi Menu ----------------

// Menu tampilan
void tampilkanMenu() {
  Serial.println("\n=== MENU PROJECT ARDUINO GWEH ===");
  Serial.println("1. Nyalakan 4 LED kelap-kelip");
  Serial.println("2. Buzzer sirine selama 5 detik");
  Serial.println("3. Lampu berjalan + buzzer");
  Serial.println("4. LED redup perlahan dengan PWM");
  Serial.println("Masukkan pilihan (1-4):");
}

// 1. LED kelap-kelip
void ledKelapKelip() {
  Serial.println("Menyalakan 4 LED kelap-kelip...");
  for (int i = 0; i < 10; i++) { // 10 kali kedip
    for (int j = 0; j < 4; j++) digitalWrite(ledPins[j], HIGH);
    delay(300);
    for (int j = 0; j < 4; j++) digitalWrite(ledPins[j], LOW);
    delay(300);
  }
}

// 2. Buzzer sirine
void buzzerSirine() {
  Serial.println("Buzzer sirine selama 5 detik...");
  unsigned long startTime = millis();
  while (millis() - startTime < 5000) {
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
  }
}

// 3. Lampu berjalan + buzzer
void lampuBerjalan() {
  Serial.println("Lampu berjalan dari kiri ke kanan + buzzer...");
  for (int i = 0; i < 10; i++) { // 10 kali geser
    for (int j = 0; j < 4; j++) {
      // Matikan semua LED dulu
      for (int k = 0; k < 4; k++) digitalWrite(ledPins[k], LOW);

      // Nyalakan LED ke-j
      digitalWrite(ledPins[j], HIGH);

      // Bunyi buzzer
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);

      delay(300);
    }
  }
  // Setelah selesai → pastikan semua LED mati
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  Serial.println("Selesai, semua LED dimatikan.");
}

// 4. Fade LED dengan PWM
void pwmFadeLed() {
  Serial.println("LED redup perlahan dengan PWM...");
  for (int i = 0; i < 4; i++) {
    analogWrite(ledPins[i], 255); // nyala penuh
  }
  delay(500);

  for (int brightness = 255; brightness >= 0; brightness -= 5) {
    for (int i = 0; i < 4; i++) {
      analogWrite(ledPins[i], brightness);
    }
    delay(100);
  }
}
