int LEDs = 2;

void setup() {

pinMode(LEDs, OUTPUT);

}
void loop() {

LED();

}

void LED() {
digitalWrite(LEDs, HIGH);
delay(1000);
digitalWrite(LEDs, LOW);
delay(1000);
}
