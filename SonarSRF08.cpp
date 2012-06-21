/*
 SonarSRF08.cpp - SRF08 sensor reader code
	 Sensor connections:
	 SDA - Analog pin 4
	 SCL - Analog pin 5
 by Zach Foresta Apr 2009
 by Leo Colomb May 2012
*/

// include Wire library to read and write I2C commands:
#include "Wire.h"
#include "SonarSRF08.h"

//#define readInches 0x50
//#define readCentimeters 0x51
//#define readMicroSeconds 0x52
//#define readGainRegister 0x00
//#define readLocation 0xFF

// Initialize Wires

void SonarSRF08::connect(){
	// start I2C bus
	Wire.begin();
}

// Communicates with Sonar to send commands

void SonarSRF08::sendCommand(int commandRegister, int address, int command, int gainRegister, int rangeLocation){
	// start I2C transmission
	Wire.beginTransmission(address);
	// send command
	Wire.write(commandRegister); // SRF08 Location 0
	Wire.write(command); // SRF08 Command
	Wire.write(gainRegister); // SRF08 Location 1
	Wire.write(rangeLocation); // SRF08 Location 2
	// end I2C transmission
	Wire.endTransmission();
}


// Sets Units for display / storage

void SonarSRF08::setUnit(int commandRegister, int address, char units, int gainRegister, int rangeLocation){
	switch(units) {
	case 'i': ;
		SonarSRF08::sendCommand(commandRegister, address, 0x50, gainRegister, rangeLocation);
		break;
	case 'c': ;
		SonarSRF08::sendCommand(commandRegister, address, 0x51, gainRegister, rangeLocation);
		break;
	case 'm': ;
		SonarSRF08::sendCommand(commandRegister, address, 0x52, gainRegister, rangeLocation);
		break;
	default:
		Serial.print("Invalid Units Entered...");
		Serial.println();
	}
}

// Set to read off the register with stored result

void SonarSRF08::setRegister(int address, int thisRegister){
	// start I2C transmission
	Wire.beginTransmission(address);
	// send address to read from
	Wire.write(thisRegister);
	// end I2C transmission
	Wire.endTransmission();
}  

// Read data from register return result

int SonarSRF08::readData(int address, int numBytes){
	int result = 0; // the result is two bytes long
	// send I2C request for data
	Wire.requestFrom(address, numBytes);
	// wait for two bytes to return
	while (Wire.available() < 2 )   {
		// wait for result
	}
	// read the two bytes, and combine them into one int
	delay(50);
	result = Wire.read() * 256;
	result += Wire.read();
	// return the result:
	return result;
}  

// Optional change Address -
// NEW_ADDRESS can be set to any of E0, E2, E4, E6, E8, EA, EC, EE
// F0, F2, F4, F6, F8, FA, FC, FE

void SonarSRF08::changeAddress(int commandRegister, int NEW_ADDRESS, int gainRegister, int rangeLocation){
	SonarSRF08::sendCommand(commandRegister, commandRegister, 0xA0, gainRegister, rangeLocation);
	SonarSRF08::sendCommand(commandRegister, commandRegister, 0xAA, gainRegister, rangeLocation);
	SonarSRF08::sendCommand(commandRegister, commandRegister, 0xA5, gainRegister, rangeLocation);
	SonarSRF08::sendCommand(commandRegister, commandRegister, NEW_ADDRESS, gainRegister, rangeLocation);
}  
