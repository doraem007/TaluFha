int LEDs = 2;
int swLED = 22;

void setup() {

  pinMode(LEDs, OUTPUT);
  pinMode(swLED, INPUT_PULLUP);

}
void loop() {
  LED();
}

void LED() {
  if (digitalRead(swLED) == LOW) {
    digitalWrite(RED, LOW);
  else {
    digitalWrite(RED, HIGH);
  }
}
