#ifndef SENSOR_H
#define SENSOR_H

void setupSensor();
bool readSensor(float &temp, float &hum);
void printSensorData(float temp, float hum);
void checkTemperatureAlert(float temp);

#endif
