int pinLed = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pinLed, 255);
  delay(200);
  analogWrite(pinLed, 128);
  delay(200);
  analogWrite(pinLed, 0);
  delay(200);
}
