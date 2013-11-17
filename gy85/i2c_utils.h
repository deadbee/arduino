#ifndef __I2C_UTILS_H__
#define __I2C_UTILS_H__

uint8_t i2c_scan();
uint8_t i2c_write(uint8_t address, uint8_t reg, uint8_t value);
uint8_t i2c_read8(uint8_t address, uint8_t reg);
int16_t i2c_read16(uint8_t address, uint8_t reg);

#endif /* __I2C_UTILS_H__ */
