const int sensor_pin = 33; // Set the ADC input pin for the soil moisture sensor (e.g., GPIO 34)
int sensor_analog;
int moisture_percent;

void setup() {
  Serial.begin(115200); // Set the baud rate to 115200 for serial communication
  Serial.println("Soil Moisture Sensor Test with ESP32");
}

void loop() {
  sensor_analog = analogRead(sensor_pin); // Read the analog value from the sensor

  // The raw analog value can range from 0 to 4095 on the ESP32 by default
  // You should calibrate this range based on your sensor's readings in air and water
  // Example calibration (update these values after testing):
  int AirValue = 3500;   // Change this to the value you get in dry air
  int WaterValue = 1920; // Change this to the value you get in water

  // Map the value to a percentage (0-100%)
  moisture_percent = map(sensor_analog, AirValue, WaterValue, 0, 100);

  // Constrain the value to be within 0 and 100
  if (moisture_percent < 0) {
    moisture_percent = 0;
  }
  if (moisture_percent > 100) {
    moisture_percent = 100;
  }

  Serial.print("Raw Sensor Value: ");
  Serial.print(sensor_analog);
  Serial.print(" | Moisture = ");
  Serial.print(moisture_percent);
  Serial.println("%");

  delay(2000); // Wait for 2 seconds before the next reading
}
