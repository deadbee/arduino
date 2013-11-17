#include "ITG3205.h"
#include "i2c_utils.h"

uint8_t itg3205_get_device_id(void)
{
  return i2c_read8(ITG3205_ADDRESS, ITG3205_REG_WHO_AM_I);
}

void itg3205_debug(void)
{
}

