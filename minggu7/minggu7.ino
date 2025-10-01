#include <SPI.h>
#include <MFRC522.h>

// Pin sesuai wiring kamu
#define SS_PIN D8   // SDA (SS)
#define RST_PIN D4  // RST

MFRC522 rfid(SS_PIN, RST_PIN); // Instance RFID
String strID;

void setup() {
  Serial.begin(115200);
  SPI.begin();        // Inisialisasi SPI
  rfid.PCD_Init();    // Inisialisasi RFID
  Serial.println("I am waiting for card...");
}

void loop() {
  // cek apakah ada kartu baru
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  // ambil ID kartu
  strID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    strID += (rfid.uid.uidByte[i] < 0x10 ? "0" : "");
    strID += String(rfid.uid.uidByte[i], HEX);
    if (i != rfid.uid.size - 1) strID += ":";
  }

  strID.toUpperCase();
  Serial.print("Kartu ID Anda : ");
  Serial.println(strID);

  // hentikan komunikasi dengan kartu
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}