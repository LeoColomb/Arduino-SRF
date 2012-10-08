/*
 SonarSRF02.cpp - SRF02 sensor reader code
	 Sensor connections:
	 SDA - Analog pin 4
	 SCL - Analog pin 5
 by Zach Foresta Apr 2009
 by Leo Colomb May 2012
*/

// include Wire library to read and write I2C commands:
#include "Wire.h"
#include "SonarSRF02.h"

void SonarSRF02::waitForCompletion(){
    delay(66);
}
