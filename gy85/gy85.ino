#include <Wire.h>
#include "i2c_utils.h"
#include "ADXL345.h"
#include "ITG3205.h"

const byte PIN_LED = 13;

void setup()
{
	int i2c_devices = 0;
	Wire.begin();
	// set Two Wire Bit Rate bitrate (i2c) to 400kHz, vs 100kHz default
	//TWBR = 12;
	Serial.begin(9600);
	pinMode(PIN_LED, OUTPUT);
	i2c_devices = i2c_scan();
	adxl345_setup();
	itg3205_setup();
}

void loop()
{  
	adxl345_debug();
	itg3205_debug();

	digitalWrite(PIN_LED, HIGH);
	delay(250);
	digitalWrite(PIN_LED, LOW);
	delay(250);
}
