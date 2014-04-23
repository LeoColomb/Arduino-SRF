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

#define readInches       0x50
#define readCentimeters  0x51
#define readMicroSeconds 0x52
#define CommandRegister  0x00
#define ResultRegister   0x02

class SonarSRF {
public:
    void         connect(int address);
    virtual void startRanging(char unit);
    virtual int  getRange(char unit, bool andStart = true);
    int          getSoft();
    void         changeAddress(int NEW_ADDRESS);
protected:
    int          getCommand(char unit);
    virtual void waitForCompletion();
    void         sendBasicCommand(int command);
    int          _address;
};

#endif
