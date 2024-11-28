#include "Sensors.h"

// MAKE SURE TO PASS BY REFERENCE (use the &)
bool Sensors::read_LSM(Adafruit_LSM6DSO32 &LSM, Vector3 &accel_data, Vector3 &gyro_data, float &temp_data) {
  sensors_event_t accel, gyro, temp;

  // Attempt to read sensor data
  if(!LSM.getEvent(&accel, &gyro, &temp))
  {
    return false;  // Return false if read fails
  }

  // Store gyroscope data
  gyro_data.x = gyro.gyro.x;
  gyro_data.y = gyro.gyro.y;
  gyro_data.z = gyro.gyro.z;

  // Store accelerometer data
  accel_data.x = accel.acceleration.x;
  accel_data.y = accel.acceleration.y;
  accel_data.z = accel.acceleration.z;

  // Store temperature data
  temp_data = float(temp.temperature);

  return true;  // Return true if read succeeds
}