#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(115200);

  // ESP32-S3 I2C pins
  Wire.begin(20, 21); // SDA, SCL

  Serial.println("Initializing MPU6050...");

  mpu.initialize();

  if (mpu.testConnection()) {
    Serial.println("✅ MPU6050 Connected Successfully!");
  } else {
    Serial.println("❌ MPU6050 Connection Failed!");
    Serial.println("Check wiring!");
    while (1);
  }
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  Serial.print("ACCEL: ");
  Serial.print(ax);
  Serial.print(", ");
  Serial.print(ay);
  Serial.print(", ");
  Serial.println(az);

  Serial.print("GYRO: ");
  Serial.print(gx);
  Serial.print(", ");
  Serial.print(gy);
  Serial.print(", ");
  Serial.println(gz);

  Serial.println("----------------");
  delay(500);
}
