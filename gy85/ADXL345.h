#ifndef __ADXL345_H__
#define __ADXL345_H__
#include "Arduino.h"

// ADXL345 accelerometer 
#define ADXL345_ADDRESS             0x53 // assuming ALT_ADDRESS is grounded
#define ADXL345_DEVID               0xE5 // device id returned by read from register ADXL345_REG_DEVID

#define ADXL345_REG_DEVID           0x00 // device id
#define ADXL345_REG_THRESH_TAP      0x1D // tap threshold
#define ADXL345_REG_OFSX            0x1E // X-axis offset
#define ADXL345_REG_OFSY            0x1F // Y-axis offset
#define ADXL345_REG_OFSZ            0x20 // Z-axis offset
#define ADXL345_REG_DUR             0x21 // tap duration
#define ADXL345_REG_LATENT          0x22 // tap latency
#define ADXL345_REG_WINDOW          0x23 // tap window
#define ADXL345_REG_THRESH_ACT      0x24 // activity threshold
#define ADXL345_REG_THRESH_INACT    0x25 // inactivity threshold
#define ADXL345_REG_TIME_INACT      0x26 // inactivity time
#define ADXL345_REG_ACT_INACT_CTL   0x27 // axis enable control for activity and inactivity detection
#define ADXL345_REG_THRESH_FF       0x28 // free-fall threshold
#define ADXL345_REG_TIME_FF         0x29 // free-fall time
#define ADXL345_REG_TAP_AXES        0x2A // axis control for single tap/double tap
#define ADXL345_REG_ACT_TAP_STATUS  0x2B // source of single tap/double tap
#define ADXL345_REG_BW_RATE         0x2C // data rate and power mode control
#define ADXL345_REG_POWER_CTL       0x2D // power-saving features control
#define ADXL345_REG_INT_ENABLE      0x2E // interrupt enable control
#define ADXL345_REG_INT_MAP         0x2F // interrupt mapping control
#define ADXL345_REG_INT_SOURCE      0x30 // source of interrupts
#define ADXL345_REG_DATA_FORMAT     0x31 // data format control
#define ADXL345_REG_DATAX0          0x32 // X-axis data 0
#define ADXL345_REG_DATAX1          0x33 // X-axis data 1
#define ADXL345_REG_DATAY0          0x34 // Y-axis data 0
#define ADXL345_REG_DATAY1          0x35 // Y-axis data 1
#define ADXL345_REG_DATAZ0          0x36 // Z-axis data 0
#define ADXL345_REG_DATAZ1          0x37 // Z-axis data 1
#define ADXL345_REG_FIFO_CTL        0x38 // FIFO control
#define ADXL345_REG_FIFO_STATUS     0x39 // FIFO status

#define ADXL345_POWER_BIT_MEASURE 0x08
#define ADXL345_DATA_FORMAT_BIT_FULL_RANGE 0x08

// settings for ADXL345_REG_BW_RATE (default: 100Hz)
// for low power mode, toggle bit5 (LOW_POWER bit)
typedef enum
{
	ADXL345_DATARATE_3200_HZ = 0b1111, // 1600Hz BW, 140mA Idd
	ADXL345_DATARATE_1600_HZ = 0b1110, //  800Hz BW,  90mA Idd
	ADXL345_DATARATE_800_HZ  = 0b1101, //  400Hz BW, 140mA Idd
	ADXL345_DATARATE_400_HZ  = 0b1100, //  200Hz BW, 140mA Idd
	ADXL345_DATARATE_200_HZ  = 0b1011, //  100Hz BW, 140mA Idd
	ADXL345_DATARATE_100_HZ  = 0b1010, //   50Hz BW, 140mA Idd
	ADXL345_DATARATE_50_HZ   = 0b1001, //   25Hz BW,  90mA Idd
	ADXL345_DATARATE_25_HZ   = 0b1000, // 12.5Hz BW,  60mA Idd
	ADXL345_DATARATE_12_5_HZ = 0b0111,
	ADXL345_DATARATE_6_25_HZ = 0b0110,
	ADXL345_DATARATE_3_13_HZ = 0b0101,
	ADXL345_DATARATE_1_56_HZ = 0b0100,
	ADXL345_DATARATE_0_78_HZ = 0b0011,
	ADXL345_DATARATE_0_39_HZ = 0b0010,
	ADXL345_DATARATE_0_20_HZ = 0b0001,
	ADXL345_DATARATE_0_10_HZ = 0b0000
} adxl345_data_rate;

typedef enum
{
	ADXL345_DATARANGE_16G = 0b11, // +- 16g
	ADXL345_DATARANGE_8G  = 0b10, // +- 8g
	ADXL345_DATARANGE_4G  = 0b01, // +- 4g
	ADXL345_DATARANGE_2G  = 0b00  // +- 2g
} adxl345_data_range;

void adxl345_set_data_range(adxl345_data_range data_range);
adxl345_data_range adxl345_get_data_range();

void adxl345_set_data_rate(adxl345_data_rate data_rate);
adxl345_data_rate adxl345_get_data_rate();

int16_t adxl345_get_x();
int16_t adxl345_get_y();
int16_t adxl345_get_z();

bool adxl345_setup();

uint8_t adxl345_get_device_id(void);

void adxl345_debug(void);

#endif /* __ADXL345_H__ */
