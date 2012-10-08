/*
 SonarSRF02.cpp - SRF02 sensor reader code
	 Sensor connections:
	 SDA - Analog pin 4
	 SCL - Analog pin 5
    By Zach Foresta April 10, 2009
    By Leo Colomb May 10, 2012
    By Philipp A. Mohrenweiser Okt 08 2012
*/
*/

// include Wire library to read and write I2C commands:
#include "Wire.h"
#include "SonarSRF08.h"

#define CommandRegister 0x00

// Communicates with Sonar to send commands


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

void SonarSRF08::waitForCompletion(){
    int result = -1;
    while(result == -1){
        result = SonarSRF::getSoft();
        delay(5);
    }

}
