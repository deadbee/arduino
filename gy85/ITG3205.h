#ifndef __ITG3205_H__
#define __ITG3205_H__
#include "Arduino.h"

#define ITG3205_ADDRESS 0x68
#define ITG3205_DEVID   0x68

#define ITG3205_REG_WHO_AM_I     0x00 // identify of the device
#define ITG3205_REG_SMPLRT_DIV   0x15 // sample rate divider
#define ITG3205_REG_DLPF_FS      0x16 // select full-scale range, LP filter BW and sample rate
#define ITG3205_REG_INT_CFG      0x17 // interrupt configuration
#define ITG3205_REG_INT_STATUS   0x1A // interrupt status
#define ITG3205_REG_TEMP_OUT_H   0x1B // temperature data (2's complement)
#define ITG3205_REG_TEMP_OUT_L   0x1C
#define ITG3205_REG_GYRO_XOUT_H  0x1D // X gyro data (2's complement)
#define ITG3205_REG_GYRO_XOUT_L  0x1E
#define ITG3205_REG_GYRO_YOUT_H  0x1F // Y gyro data (2's complement)
#define ITG3205_REG_GYRO_YOUT_L  0x20
#define ITG3205_REG_GYRO_ZOUT_H  0x21 // Z gyro data (2's complement)
#define ITG3205_REG_GYRO_ZOUT_L  0x22
#define ITG3205_REG_PWR_MGM      0x3E // power management

// bit[0:2] of PWR_MGM to select clock source
typedef enum
{
  ITG3205_CLK_SEL_INTERNAL_OSCILLATOR     = 0,
  ITG3205_CLK_SEL_PLL_X_GYRO_REF          = 1,
  ITG3205_CLK_SEL_PLL_Y_GYRO_REF          = 2,
  ITG3205_CLK_SEL_PLL_Z_GYRO_REF          = 3,
  ITG3205_CLK_SEL_PLL_EXT_32_768_KHZ_REF  = 4,
  ITG3205_CLK_SEL_PLL_EXT_19_2_MHZ_REF    = 5,
} itg3205_clk_sel;


uint8_t itg3205_get_device_id(void);

bool itg3205_setup(void);

void itg3205_debug(void);

#endif /* ITG3205_H__ */
