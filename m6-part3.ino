#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include "DHT.h"

// === KONFIGURASI WIFI ===
#define WIFI_SSID "SKK - STUDENT"
#define WIFI_PASSWORD ""

// === KONFIGURASI FIREBASE ===
#define FIREBASE_HOST "https://console.firebase.google.com/project/iot-f88b4/database/iot-f88b4-default-rtdb/data/~2F?hl=id"   // Ganti dengan Firebase project Bos
#define FIREBASE_AUTH "reFyLvYx4abW47IWQoCSUKku0a9UZfjVWPQ2rhe8" // Ganti dengan secret Firebase

// Email/Password akun Firebase Authentication
#define USER_EMAIL "e41230453@student.polije.ac.id"
#define USER_PASSWORD "frytdtmjy"

// === KONFIGURASI DHT11 ===
#define DHTPIN D3        // pin data DHT11 ke D3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Buat objek Firebase
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Koneksi WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Menghubungkan ke WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi terhubung!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Konfigurasi Firebase
  config.host = FIREBASE_HOST;
  config.api_key = FIREBASE_AUTH;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  // Mulai koneksi Firebase
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal membaca DHT11!");
    delay(2000);
    return;
  }

  Serial.print("Kelembaban: ");
  Serial.print(h);
  Serial.print(" %  |  Suhu: ");
  Serial.print(t);
  Serial.println(" °C");

  // Simpan ke Firebase
  if (Firebase.setFloat(fbdo, "/DHT11/Humidity", h)) {
    Serial.println("Kelembaban terkirim ke Firebase");
  } else {
    Serial.println("Gagal kirim kelembaban: " + fbdo.errorReason());
  }

  if (Firebase.setFloat(fbdo, "/DHT11/Temperature", t)) {
    Serial.println("Suhu terkirim ke Firebase");
} else {
    Serial.println("Gagal kirim suhu: " + fbdo.errorReason());
  }

  delay(5000);
}
