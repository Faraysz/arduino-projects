#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define WIFI_SSID "SSK - STUDENT"
#define WIFI_PASSWORD ""

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup() {
  Serial.begin(115200);

  // Koneksi ke WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());

  // Konfigurasi Firebase
  config.host = "iot-rfid-3ba2e-default-rtdb.firebaseio.com";
  config.signer.tokens.legacy_token = "sNfzyoTHoc4hcfP3f2M3G33DKeeUGwsB7Q0ykUWW";

  // Mulai Firebase
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  // Tes kirim data
  if (Firebase.setString(fbdo, "/test", "Hello RFID")) {
    Serial.println("Data sent to Firebase!");
  } else {
    Serial.println("Error: " + fbdo.errorReason());
  }
}

void loop() {
}