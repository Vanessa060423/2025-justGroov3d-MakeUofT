#include <SPI.h>

#define CS_PIN 10 // Chip Select (CS) for ADXL362

void setup() {
  Serial.begin(9600);  // Start Serial Monitor

  SPI.begin();         // Start SPI communication
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH); // Deselect ADXL362
  delay(100);

  // Initialize ADXL362
  writeRegister(0x1F, 0x52); // Reset device
  delay(100);
  writeRegister(0x2D, 0x02); // Set to measurement mode
}

int x_offset = -114; // Calibrate based on sensor
int y_offset = 27;   // Calibrate based on sensor

void loop() {
  // Read Flex Sensor Values
  int flex1 = analogRead(A0); // Flex Sensor 1
  int flex2 = analogRead(A1); // Flex Sensor 2

  // Read Accelerometer (X, Y, Z)
  int x = readAxis(0x0E) - x_offset;
  int y = readAxis(0x10) - y_offset;
  int z = readAxis(0x12);

  // Print Flex Sensor Readings
 if (flex1 > 400) {
    Serial.print("Flex1: ");
    Serial.print(flex1);
    Serial.print("|");
  }
  
  if (flex2 > 400) {
    Serial.print("Flex2: ");
    Serial.print(flex2);
    Serial.print("|");
  }

  // Print Accelerometer Readings
  Serial.print("X: ");
  Serial.print(x);
  Serial.print("| Y: ");
  Serial.print(y);
  Serial.print("| Z: ");
  Serial.println(z); // Move to the next line

  delay(500); // Delay to make output readable
}

// Function to write to ADXL362 register
void writeRegister(byte reg, byte value) {
  digitalWrite(CS_PIN, LOW);
  SPI.transfer(0x0A); // Write command
  SPI.transfer(reg);
  SPI.transfer(value);
  digitalWrite(CS_PIN, HIGH);
}

// Function to read ADXL362 axis data
int readAxis(byte reg) {
  digitalWrite(CS_PIN, LOW);
  SPI.transfer(0x0B); // Read command
  SPI.transfer(reg);
  byte lowByte = SPI.transfer(0x00);
  byte highByte = SPI.transfer(0x00);
  digitalWrite(CS_PIN, HIGH);
  return (highByte << 8) | lowByte; // Combine high and low byte
}
