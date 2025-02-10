#include "DHT.h"
#define DHTPIN 15
#define DHTTYPE DHT22
int RED = 2;
int YELLOW = 3;
int GREEN = 4;
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial1.begin(115200);
  Serial1.println("DHTxx test!");
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  dht.begin();
}
void loop() {
  readDHT();
}
void readDHT() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    Serial1.println("Failed to read from DHT");
    return;
  }
  Serial1.print("Humidity: ");
  Serial1.print(h);
  Serial1.print(" %\t");
  Serial1.print("Temperature: ");
  Serial1.print(t);
  Serial1.println(" *C");
  controlLED(t);
  delay(500);
}
void controlLED(float temperature) {
  if (temperature >= 40) {
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
  } else if (temperature >= 32) {
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(RED, LOW);
  } else if (temperature >= 20) {
    digitalWrite(GREEN, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
  } else {
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
  }
}
