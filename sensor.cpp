#include "sensor.h"
#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYPE DHT22
#define TEMP_ALERT_THRESHOLD_C 40.0

DHT dht(DHT_PIN, DHT_TYPE);

void setupSensor() {
  dht.begin();
}

bool readSensor(float &temp, float &hum) {
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    return false;
  }
  return true;
}

void printSensorData(float temp, float hum) {
  Serial.print("Temperature: ");
  Serial.print(temp, 1);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(hum, 0);
  Serial.println(" %");
}

void checkTemperatureAlert(float temp) {
  if (temp > TEMP_ALERT_THRESHOLD_C) {
    Serial.println("ALERT: High Temperature");
  }
}
