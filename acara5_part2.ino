int pinLed[]= {6};

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
  Serial.println("Masukkan 1 --> nyala atau 2 --> padam");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    int kondisi=Serial.parseInt();
    if(kondisi==1)
    {
      digitalWrite(pinLed,HIGH);
      Serial.println("LED MENYALA");
      for (int i = 0; i < 10; i++) { // 10 kali geser
    for (int j = 0; j < 4; j++) {
      // Nyalakan LED ke-j
      digitalWrite(pinLed[j], HIGH);
      delay(300);
     }
    }
    if(kondisi==2)
    {
      digitalWrite(pinLed, LOW);
      Serial.println("LED PADAM");
        // Matikan semua LED dulu
      for (int k = 0; k < 4; k++) digitalWrite(pinLed[k], LOW);
    }
  }
}
}
