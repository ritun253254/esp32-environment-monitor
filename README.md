# ESP32 Environmental Monitoring System  

## Description  
This project is a simple IoT-based environmental monitoring system using ESP32 and a DHT22 sensor. It measures temperature and humidity in real time and sends the data over the internet for remote monitoring.  

## Components Used  
- ESP32 Microcontroller  
- DHT22 Sensor  
- WiFi  
- MQTT  

## Working  
The ESP32 connects to WiFi, reads sensor data, displays it on the serial monitor, and sends it to an MQTT broker in JSON format. The system runs continuously and reconnects automatically if needed.  

## Features  
- Real-time monitoring  
- WiFi + MQTT communication  
- Continuous execution using millis()  
- Auto reconnect  

## Output  
Temperature and humidity are shown on the serial monitor and sent to the cloud.  

## Simulation  
https://wokwi.com/projects/468982118421528577  

## Author  
Ritun Panigrahi  
