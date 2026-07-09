#include "mqtt_manager.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#define MQTT_BROKER "test.mosquitto.org"
#define MQTT_PORT 1883
#define MQTT_TOPIC "iot/esp32_001/env"

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void setupMQTT() {
  mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
}

void connectMQTT() {
  if (mqttClient.connect("ESP32_001")) {
    Serial.println("[MQTT] Connected.");
  }
}

void handleMQTT() {
  static unsigned long lastMqttRetry = 0;

  if (!mqttClient.connected()) {
    if (millis() - lastMqttRetry > 5000) {
      connectMQTT();
      lastMqttRetry = millis();
    }
  } else {
    mqttClient.loop();
  }
}

void publishData(float temp, float hum) {
  if (!mqttClient.connected()) return;

  JsonDocument doc;
  doc["deviceId"] = "ESP32_001";
  doc["temperature"] = temp;
  doc["humidity"] = hum;
  doc["timestamp"] = String(millis());

  char buffer[200];
  serializeJson(doc, buffer);

  mqttClient.publish(MQTT_TOPIC, buffer);

  Serial.print("[MQTT] Published: ");
  Serial.println(buffer);
}
