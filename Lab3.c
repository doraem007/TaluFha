int LEDs = 2;
int swLED = 13;

void setup() {

  pinMode(LEDs, OUTPUT);
  pinMode(swLED, INPUT_PULLUP);

}
void loop() {
  LED();
}

void LED() {
  if (digitalRead(swLED) == HIGH) {
    digitalWrite(LEDs, LOW);}
  else {
    digitalWrite(LEDs, HIGH);
  }
}
