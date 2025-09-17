#include "DHT.h"

#define DHTPIN D2        // Pin data DHT22 terhubung ke pin digital 2 Arduino
#define DHTTYPE DHT22   // Tipe sensor DHT yang digunakan adalah DHT22 (AM2302)

// Inisialisasi objek DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200); 
  Serial.println(F("DHT22 example!"));

  dht.begin(); // Mulai komunikasi dengan sensor
}

void loop() {
  // Baca suhu dan kelembaban
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Cek apakah pembacaan gagal
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Tampilkan hasil di Serial Monitor
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(temperature);
  Serial.println(F("°C "));

  // Tunggu 2 detik sebelum pembacaan berikutnya
  delay(2000);
}