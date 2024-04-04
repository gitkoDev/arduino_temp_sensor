#include "DHT.h"
#define DHTPIN 5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int sensorPin = A0;
float sensorVoltage = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);

  for (int i = 2; i < 5; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

  dht.begin();

}

void loop() {
  delay(2000);

  float sensorTemp = dht.readTemperature();
  float sensorHumid = dht.readHumidity();

  Serial.print("Temperature: ");
  Serial.println(sensorTemp);
  Serial.print("Humidity: ");
  Serial.println(sensorHumid);
}
