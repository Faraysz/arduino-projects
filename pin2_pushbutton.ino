int button1 = 2;
int pinLed = 6;

int btnState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLed, OUTPUT);
  pinMode(button1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  btnState = digitalRead(button1);

  if (btnState == LOW) {
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
  }
}
