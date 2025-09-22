#include <SoftwareSerial.h>
#include <TinyGPS++.h>

int pinRxBuatan = D5;   // Pin RX software serial
int pinTxBuatan = D6;   // Pin TX software serial

// Membuat port serial buatan
SoftwareSerial gpsSerial(pinRxBuatan, pinTxBuatan); 
TinyGPSPlus gps;  // Buat objek gps

void setup() {
  Serial.begin(19200);    // Serial monitor ke komputer
  gpsSerial.begin(9600);  // Baudrate komunikasi GPS
}

void loop() {
  while (gpsSerial.available() > 0) {
    byte buffer = gpsSerial.read();  
    Serial.write(buffer);   // Tampilkan data NMEA ke Serial Monitor
  }
  delay(100);
}
