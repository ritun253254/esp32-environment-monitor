#include <Arduino.h>
#include "sensor.h"
#include "wifi_manager.h"
#include "mqtt_manager.h"

#define SENSOR_READ_INTERVAL_MS 5000

unsigned long lastRead = 0;

void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println("=== ESP32 Environmental Monitor ===");

  setupSensor();
  setupWiFi();
  setupMQTT();
}

void loop() {
  handleWiFi();
  handleMQTT();

  if (millis() - lastRead >= SENSOR_READ_INTERVAL_MS) {
    lastRead = millis();

    float temp, hum;

    if (!readSensor(temp, hum)) {
      Serial.println("[Sensor] Read failed.");
      return;
    }

    printSensorData(temp, hum);
    checkTemperatureAlert(temp);
    publishData(temp, hum);
  }
}
