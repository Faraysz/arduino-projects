#include <ESP8266WiFi.h>
#include <DHT.h>

#define DHTPIN D2 // Digital pin connected to DHT11
#define DHTTYPE DHT11 // Initialize dht type as DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);
  dht.begin(); //reads dht sensor data
}

void loop()
{
  float h = dht.readHumidity(); // Read Humidity
  float t = dht.readTemperature(); // Read temperature

  if (isnan(h) || isnan(t)) // Checking sensor working
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print("Kelembapan/Hum: ");
  Serial.print(h);
  String fireHumid = String(h) + String("&"); //Humidity integer to string conversion
  Serial.print("°C Temp/Suhu: ");
  Serial.print(t);
  Serial.println("°C");
  String fireTemp = String(t) + String("°C"); //Temperature integer to string conversion
  delay(5000);
}