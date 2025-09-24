#include <SoftwareSerial.h>
#include <TinyGPS++.h>

int pinRXBuatan = D5;
int pinTXBuatan = D6;

SoftwareSerial gpsSerial(pinRXBuatan, pinTXBuatan);
TinyGPSPlus gps;

void setup() {
  Serial.begin(19200);
  gpsSerial.begin(9600);
}  

void loop(){
    while(gpsSerial.available() > 0){
        byte buffer = gpsSerial.read();
        Serial.write(buffer);
    }
    delay(1000);
}