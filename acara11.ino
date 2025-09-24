#include <SoftwareSerial.h>

int pinRxBuatan = 4;   // Pin RX untuk komunikasi dengan Wemos
int pinTxBuatan = 3;   // Pin TX untuk komunikasi dengan Wemos

// Membuat port serial baru bernama wemosSerial
SoftwareSerial wemosSerial(pinRxBuatan, pinTxBuatan);

void setup() {
  Serial.begin(9600);         // Buka Serial Monitor (PC) dengan baudrate 9600
  wemosSerial.begin(19200);   // Buka komunikasi dengan Wemos D1 Mini pada baudrate 19200
}

void loop() {
  // Cek apakah ada data yang dikirim Wemos ke Arduino
  while (wemosSerial.available() > 0) {
    byte buffer = wemosSerial.read();   // Baca data dari Wemos
    Serial.write(buffer);               // Kirim data ke Serial Monitor
  }
  delay(100);
}
