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
