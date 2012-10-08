/*
    SonarSRF08.cpp - SRF08 sensor reader code
        By Zach Foresta April 10, 2009
        By Leo Colomb May 10, 2012
        By Philipp A. Mohrenweiser Okt 08 2012
*/


#include "SonarSRF08.h"

/**
 * Additional commands for gain and range
 */
void SonarSRF08::startRanging(char unit){
	// start I2C transmission
	Wire.beginTransmission(_address);
	// send command
	Wire.write(CommandRegister); // SRF02 Location 0
	Wire.write(getCommand(unit)); // SRF02 Command
	// end I2C transmission
    Wire.write(0x00);
    Wire.write(0xFF);
	Wire.endTransmission();
}

