int ledPin = 6;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int dutyCycle = 0 ; dutyCycle <= 255; dutyCycle +=5)
  {
    analogWrite(ledPin, dutyCycle);
    delay(100);
  }
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle -= 5)
  {
    analogWrite(ledPin, dutyCycle);
    delay(100);
  }
}
