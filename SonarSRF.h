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

// Sensor connections:
// * SDA - Analog pin 4
// * SCL - Analog pin 5

#ifndef SonarSRF_h
#define SonarSRF_h

#include <Wire.h>
#include <Arduino.h>

#define INCHES           0x50
#define CENTIMETERS      0x51
#define MICROSECONDS     0x52
#define COMMAND_REGISTER (byte)0x00
#define RESULT_REGISTER  0x02

class SonarSRF
{
public:
    void         connect(int address, int gainRegister = NULL, int rangeLocation = NULL);
    virtual void startRanging(char unit);
    virtual int  getRange(char unit = 'c', bool andStart = true);
    int          getSoft();
    void         changeAddress(int newAddress);

protected:
    virtual void waitForCompletion();
    void         sendCommand(int command = NULL, int addressRegister = COMMAND_REGISTER);
    int          _address;
    int          _gainRegister;
    int          _rangeLocation;
};

#endif
