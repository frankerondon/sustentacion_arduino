

#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include "I2Cdev.h"
#define OUTPUT_TEAPOT


MPU6050 sensor;

int ax, ay, az;
int gx, gy, gz;
void setup() {
 Serial.begin(57600); 
 Wire.begin(); 
 sensor.initialize(); 
 if (sensor.testConnection()) Serial.println("Sensor iniciado correctamente");
 else Serial.println("Error al iniciar el sensor");
}
void loop() {
 
 sensor.getAcceleration(&ax, &ay, &az);
 sensor.getRotation(&gx, &gy, &gz);
 
 Serial.print("a[x y z] g[x y z]:\t");
 Serial.print(ax); Serial.print("\t");
 Serial.print(ay); Serial.print("\t");
 Serial.print(az); Serial.print("\t");
 Serial.print(gx); Serial.print("\t");
 Serial.print(gy); Serial.print("\t");
 Serial.println(gz);
 delay(100);
} 
