const int ledPins[] = {7, 8, 12, 13};  
const int btn1 = 1;
const int btn2 = 2;
const int buzzer = 10;

bool lastBtn1 = HIGH;
bool lastBtn2 = HIGH;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buzzer, OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
}

void loop() {
  bool currentBtn1 = digitalRead(btn1);
  bool currentBtn2 = digitalRead(btn2);

  // Tombol 1 ditekan
  if (lastBtn1 == HIGH && currentBtn1 == LOW) {

    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], HIGH);
      tone(buzzer, 1000);
      delay(300);
      digitalWrite(ledPins[i], LOW);
      noTone(buzzer);
      delay(200);
      }

      for (int i = 2; i >= 0; i--) {
      digitalWrite(ledPins[i], HIGH);
      tone(buzzer, 1000);
      delay(300);
      digitalWrite(ledPins[i], LOW);
      noTone(buzzer);
      delay(200);
    }
  }
  lastBtn1 = currentBtn1;

  // Tombol 2 ditekan
  if (lastBtn2 == HIGH && currentBtn2 == LOW) {
    // Kanan
    for (int i = 0; i < 4; i++) {
      for (int duty = 0; duty <= 255; duty += 5) {
        analogWrite(ledPins[i], duty);
        delay(5);
      }
      for (int duty = 255; duty >= 0; duty -= 5) {
        analogWrite(ledPins[i], duty);
        delay(5);
      }
    }
    // Kiri
    for (int i = 2; i >= 0; i--) {
      for (int duty = 0; duty <= 255; duty += 5) {
        analogWrite(ledPins[i], duty);
        delay(5);
      }
      for (int duty = 255; duty >= 0; duty -= 5) {
        analogWrite(ledPins[i], duty);
        delay(5);
      }
    }
    // Matikan semua LED
    for (int i = 0; i < 4; i++) {
      analogWrite(ledPins[i], 0);
    }
  }
  lastBtn2 = currentBtn2;
}