int buzzer = 10;   // pin buzzer
int button1 = 1;  // tombol 1
int button4 = 4;  // tombol 4

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
}

void loop() {
  int btn1 = digitalRead(button1);
  int btn4 = digitalRead(button4);

  if (btn1 == LOW) {
    tone(buzzer, 1000); // beep panjang 1000 Hz
    delay(200);
    noTone(buzzer);
    delay(200);
  } 
  else if (btn4 == LOW) {
    tone(buzzer, 1500); // beep panjang 1500 Hz
  } 
  else {
    noTone(buzzer); // matikan suara
  }
}
