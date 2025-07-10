#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup(){
  Wire.begin();
  Serial.begin(9600);
  mpu.initialize();
}

void loop(){
  int16_t ax,ay,az;
  mpu.getAcceleration(&ax,&ay,&az);
  
  float ax_g = ax/16384.0;
  float ay_g = ay/16384.0;
  float az_g = az/16384.0;

  float pitch = atan2(ax_g, sqrt(ay_g*ay_g + az_g*az_g))*180/PI;
  float roll = atan2(ay_g, sqrt(ax_g*ax_g + az_g*az_g))*180/PI;

  Serial.print("Pitch: "); Serial.print(pitch);
  Serial.print("°, Roll: "); Serial.print(roll);Serial.print("° | ");

  if(abs(pitch)<5 && abs(roll)<5) Serial.print("Flat Surface! 🟩\n");
  else Serial.print("Tilted! 📐\n");

  delay(500);
}