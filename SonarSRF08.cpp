//
// SonarSRF
// Arduino Library for controlling SRF sonar sensors
// http://www.arduino.cc/playground/Main/SonarSrf08
//
// MIT License
// Copyright(c) 2009 Zach Foresta
// Copyright(c) 2012 Leo Colombaro
// Copyright(c) 2012 Philipp A. Mohrenweiser
//

#include "SonarSRF08.h"

// Additional commands for gain and range
void SonarSRF08::startRanging(char unit) {
    // start I2C transmission
    Wire.beginTransmission(_address);
    // send command
    Wire.write(CommandRegister); // SRF02 Location 0
    Wire.write(getCommand(unit)); // SRF02 Command
    // end I2C transmission
    Wire.endTransmission();
}

// Sets Units for display / storage
void SonarSRF08::setUnit(int commandRegister, int address, char units, int gainRegister, int rangeLocation) {
    switch (units) {
    case 'i':;
        SonarSRF08::sendCommand(commandRegister, address, 0x50, gainRegister, rangeLocation);
        break;
    case 'c':;
        SonarSRF08::sendCommand(commandRegister, address, 0x51, gainRegister, rangeLocation);
        break;
    case 'm':;
        SonarSRF08::sendCommand(commandRegister, address, 0x52, gainRegister, rangeLocation);
        break;
    default:
        Serial.print("Invalid Units Entered...");
        Serial.println();
    }
}

// Set to read off the register with stored result
void SonarSRF08::setRegister(int address, int thisRegister) {
    // start I2C transmission
    Wire.beginTransmission(address);
    // send address to read from
    Wire.write(thisRegister);
    // end I2C transmission
    Wire.endTransmission();
}

// Read data from register return result
int SonarSRF08::readData(int address, int numBytes) {
    int result = 0; // the result is two bytes long
    // send I2C request for data
    Wire.requestFrom(address, numBytes);
    // wait for two bytes to return
    while (Wire.available() < 2) {
        // wait for result
    }
    // read the two bytes, and combine them into one int
    delay(50);
    result = Wire.read() * 256;
    result += Wire.read();
    // return the result:
    return result;
}
