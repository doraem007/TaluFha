int LEDs = 25;

void setup() {

  pinMode(LEDs, OUTPUT);

}
void loop() {
  LED();
}
void LED() {
  digitalWrite(LEDs, HIGH);
  delay(100);
  digitalWrite(LEDs, LOW);
}