/*
	SonarSRF.h - library for controlling SRF0x sonar sensors
		By Zach Foresta April 10, 2009
		By Leo Colomb May 10, 2012
        By Philipp A. Mohrenweiser Okt 08 2012
*/

#include "SonarSRF.h"

void SonarSRF::connect(int address){
    _address = address;
	// start I2C bus
	Wire.begin();
}

void SonarSRF::startRanging(char unit){
	sendBasicCommand(getCommand(unit));
}
// Communicates with Sonar to send commands

void SonarSRF::sendBasicCommand(int command){
	// start I2C transmission
	Wire.beginTransmission(_address);
	// send command
	Wire.write(CommandRegister); // SRF02 Location 0
	Wire.write(command); // SRF02 Command
	// end I2C transmission
	Wire.endTransmission();
}


// Sets Units for display / storage

int SonarSRF::getCommand(char units){
    switch(units) {
        case 'i': ;
            return (readInches);
            break;
        case 'c': ;
            return (readCentimeters);
            break;
        case 'm': ;
            return (readMicroSeconds);
            break;
        default:
            Serial.print("Invalid Units Entered... using readMicroSeconds");
            Serial.println();
            return readMicroSeconds;
    }
}


// Read data from register return result

int SonarSRF::getRange(char unit, bool andStart){
    if (andStart == true) { 
        startRanging(unit);
        waitForCompletion();
    }
    
	int result = 0; // the result is two bytes long
	// send I2C request for data
    
    Wire.beginTransmission(_address);             // start communicating with SRFmodule
    Wire.write(ResultRegister);                           // Call the register for start of ranging data
    Wire.endTransmission();

	Wire.requestFrom(_address, 2);
	// wait for two bytes to return
    int i = 0;
	while (Wire.available() < 2 )   {
    delay(1);
	}
	// read the two bytes, and combine them into one int
	result = Wire.read() * 256;
	result += Wire.read();
	// return the result:
	return result;
}  

void SonarSRF::waitForCompletion(){
    int result = -1;
    while(result == -1){
        result = getSoft();
        delay(2);
    }
}

int SonarSRF::getSoft(){  // Function to get software revision
  
    Wire.beginTransmission(_address);   // Begin communication with the SRF module
    Wire.write(CommandRegister);        // Sends the command bit, when this bit is read it returns the software revision
    Wire.endTransmission();

    Wire.requestFrom(_address, 1);      // Request 1 byte
    while(Wire.available() < 0);        // While byte available
    int software = Wire.read();         // Get byte

    return(software);                               
  
}
/**
 * The address given in arduino 7bit has to be converted back into SRF 8bit
 * NEW_ADDRESS << 1 can be set to any of E0, E2, E4, E6, E8, EA, EC, EE
 * F0, F2, F4, F6, F8, FA, FC, FE
 */
void SonarSRF::changeAddress(int NEW_ADDRESS){
    SonarSRF::sendBasicCommand(0xA0);
    SonarSRF::sendBasicCommand(0xAA);
    SonarSRF::sendBasicCommand(0xA5);
    SonarSRF::sendBasicCommand(NEW_ADDRESS << 1);
}  
