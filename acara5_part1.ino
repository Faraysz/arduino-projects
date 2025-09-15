int pinLed = 6;

void setup() {
  // dijalankan sekali saat board Arduino dinyalakan
  pinMode(pinLed, OUTPUT);       // pin 6 sebagai output
  Serial.begin(9600);            // komunikasi serial dengan baudrate 9600
}

void loop() {
  // dijalankan berulang-ulang selama Arduino menyala
  digitalWrite(pinLed, HIGH);    // menyalakan LED
  Serial.println("LED MENYALA"); // menampilkan pesan ke Serial Monitor
  delay(100);                    // jeda 100 ms

  digitalWrite(pinLed, LOW);     // mematikan LED
  Serial.println("LED PADAM");   // menampilkan pesan ke Serial Monitor
  delay(100);                    // jeda 100 ms
}
