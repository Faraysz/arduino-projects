int pinLed = 6;
int button = 2;
int bacaButton, lastButton, kondisi = 0;

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  bacaButton = digitalRead(button);

  if ((bacaButton == HIGH) && (lastButton == LOW)) {
    kondisi = 1 - kondisi;
    delay(10);
  }

  lastButton = bacaButton;

  if (kondisi == 1) {
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
  }
}
