#include "Arduino.h"
#include <Wire.h>
#include "i2c_utils.h"

uint8_t i2c_scan()
{
  byte i2c_address, i2c_error;
  int i2c_devices = 0;
  
  Serial.println("Scanning..");
  
  // iterate over the i2c address space
  for ( i2c_address = 1; i2c_address < 127; i2c_address++ )
  {
    Wire.beginTransmission(i2c_address);
    i2c_error = Wire.endTransmission();
    
    switch ( i2c_error )
    {
      case 0: // success
        Serial.print("i2c device found at address 0x");
        Serial.println(i2c_address, HEX);
        i2c_devices++;
        break;
        
      case 1: // data too long to fit in transmit buffer
      case 2: // received NACK on transmit of address
      case 3: // received NACK on transmit of data
      case 4: // other error
        break;
    }
  }
  Serial.print(i2c_devices);
  Serial.println(" device(s) found");

  return i2c_devices;
}

uint8_t i2c_write(uint8_t address, uint8_t reg, uint8_t value)
{
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.write(value);
  
  return Wire.endTransmission();
}

uint8_t i2c_read8(uint8_t address, uint8_t reg)
{
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(address, (uint8_t)1);
  
  return Wire.read();
}

int16_t i2c_read16(uint8_t address, uint8_t reg)
{
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(address, (uint8_t)2);
  return (int16_t)(Wire.read() | Wire.read() << 8);
}
