#include "wifi_manager.h"
#include <WiFi.h>

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""

void setupWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("[WiFi] Connecting...");
}

void handleWiFi() {
  static unsigned long lastRetry = 0;

  if (WiFi.status() != WL_CONNECTED) {
    if (millis() - lastRetry > 5000) {
      WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
      Serial.println("[WiFi] Reconnecting...");
      lastRetry = millis();
    }
  }
}
