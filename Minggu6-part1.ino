#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <DHT.h>

#define WIFI_SSID "SKK - STUDENT"
#define WIFI_PASSWORD ""

// Hapus https:// dan cukup tulis hostname saja
#define FIREBASE_HOST "iot-f88b4-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH ""  

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup() {
  Serial.begin(115200);
  
  // Koneksi WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.println("Connected with IP: ");
  Serial.println(WiFi.localIP());

  // Konfigurasi Firebase
config.database_url = "https://iot-f88b4-default-rtdb.firebaseio.com/"; 
config.signer.tokens.legacy_token = "reFyLvYx4abW47IWQoCSUKku0a9UZfjVWPQ2rhe8";

// Inisialisasi Firebase
Firebase.begin(&config, &auth);
Firebase.reconnectWiFi(true);
  // Inisialisasi DHT11
  dht.begin();
  
  Serial.println("Setup selesai!");
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  Serial.print("Suhu: ");
  Serial.print(t);
  Serial.print("°C | Kelembapan: ");
  Serial.print(h);
  Serial.println("%");

  // Kirim data ke Firebase
  if (Firebase.setFloat(fbdo, "/sensor/suhu", t)) {
    Serial.println("✓ Suhu berhasil dikirim");
  } else {
    Serial.println("✗ Gagal kirim suhu: " + fbdo.errorReason());
  }

  if (Firebase.setFloat(fbdo, "/sensor/kelembapan", h)) {
    Serial.println("✓ Kelembapan berhasil dikirim");
  } else {
    Serial.println("✗ Gagal kirim kelembapan: " + fbdo.errorReason());
  }

  delay(5000); 
}