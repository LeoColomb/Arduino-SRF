//
// SonarSRF
// Arduino Library for controlling SRF sonar sensors
// http://www.arduino.cc/playground/Main/SonarSrf08
//
// MIT License
// Copyright(c) 2009 Zach Foresta
// Copyright(c) 2012 Philipp A. Mohrenweiser
// Copyright(c) 2012-2016 Leo Colombaro
//

// Sensor connections:
// * SDA - Analog pin 4
// * SCL - Analog pin 5

#ifndef SONARSRF_H
#define SONARSRF_H

#include <Wire.h>
#include <Arduino.h>

// Read
#define SOFTWARE_REVISION 0x00
#define LIGHT_SENSOR      0x01
// Write
#define COMMAND_REGISTER  0x00
#define MAX_GAIN_REGISTER 0x01
#define RANGE_REGISTER    0x02
// Units
#define INCHES            0x50
#define CENTIMETERS       0x51
#define MICROSECONDS      0x52

class SonarSRF
{
public:
    void         begin(int address, int gainRegister = 0, int rangeLocation = 0);
    virtual void startRanging(char unit);
    virtual int  getRange(char unit = 'c', bool andStart = true);
    int          getVersion();
    void         setAddress(int newAddress);
protected:
    virtual void waitForCompletion();
    void         sendCommand(int command = 0, int addressRegister = COMMAND_REGISTER);
    int          _address;
    int          _gainRegister;
    int          _rangeLocation;
};

#endif // SONARSRF_H
