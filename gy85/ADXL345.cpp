#include "ADXL345.h"
#include "i2c_utils.h"

void adxl345_set_data_range(adxl345_data_range data_range)
{
  uint8_t data_format = i2c_read8(ADXL345_ADDRESS, ADXL345_REG_DATA_FORMAT);
  
  data_format &= ~0x0F; // reset lower 4 bits
  data_format |= data_range; // set new data range
  
  // enable full res bit
  data_format |= ADXL345_DATA_FORMAT_BIT_FULL_RANGE;
  
//  data_format |= 0x4;
  
  i2c_write(ADXL345_ADDRESS, ADXL345_REG_DATA_FORMAT, data_format);
  
}

adxl345_data_range adxl345_get_data_range()
{
  return (adxl345_data_range)(i2c_read8(ADXL345_ADDRESS, ADXL345_REG_DATA_FORMAT) & 0x03);
}

void adxl345_set_data_rate(adxl345_data_rate data_rate)
{
  i2c_write(ADXL345_ADDRESS, ADXL345_REG_BW_RATE, data_rate);
}

adxl345_data_rate adxl345_get_data_rate()
{
  return (adxl345_data_rate)(i2c_read8(ADXL345_ADDRESS, ADXL345_REG_BW_RATE) & 0x0F);
}

int16_t adxl345_get_x()
{
  return (int16_t)(i2c_read16(ADXL345_ADDRESS, ADXL345_REG_DATAX0));
}

int16_t adxl345_get_y()
{
  return (int16_t)(i2c_read16(ADXL345_ADDRESS, ADXL345_REG_DATAY0));
}

int16_t adxl345_get_z()
{
  return (int16_t)(i2c_read16(ADXL345_ADDRESS, ADXL345_REG_DATAZ0));
}

bool adxl345_setup()
{
  if ( ADXL345_DEVID != adxl345_get_device_id() )
  {
    Serial.println("ADXL345 device not found!");
    return false;
  }
  
  // put the device into measurement mode
  i2c_write(ADXL345_ADDRESS, ADXL345_REG_POWER_CTL, ADXL345_POWER_BIT_MEASURE );
  adxl345_set_data_range(ADXL345_DATARANGE_16G);
  
  return true;
}

uint8_t adxl345_get_device_id(void)
{
  return i2c_read8(ADXL345_ADDRESS, ADXL345_REG_DEVID);
}

void adxl345_debug(void)
{
  adxl345_data_rate data_rate = adxl345_get_data_rate();
  adxl345_data_range data_range = adxl345_get_data_range();
  float x = adxl345_get_x() * 0.0039 * -1.0;// * 0.0039 * -1.0;// * 0.004 * 9.81;
  float y = adxl345_get_y() * 0.0039 * -1.0;// * 0.0039 * -1.0;// * 0.004 * 9.81;
  float z = adxl345_get_z() * 0.0039;// * 0.0039;// * 0.004 * 9.81;
  float len = sqrt(x*x + y*y + z*z);
  float x_angle = acos(x/len) * 57.3;
  float y_angle = acos(y/len) * 57.3;
  float z_angle = acos(z/len) * 57.3;

  
  Serial.print("ADXL345 RATE: ");
  Serial.print(data_rate, BIN);
  Serial.print(" RANGE: ");
  Serial.print(data_range, BIN);
  Serial.print(" X: ");
  Serial.print(x);
  Serial.print(" Y: ");
  Serial.print(y);
  Serial.print(" Z: ");
  Serial.print(z);
  Serial.print(" angle: ");
  Serial.print(x_angle);
  Serial.print(", ");
  Serial.print(y_angle);
  Serial.print(", ");
  Serial.println(z_angle);
}
