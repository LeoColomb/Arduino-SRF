//
// SonarSRF08.h
// Library for controlling SRF08 sonar sensors
// http://www.arduino.cc/playground/Main/SonarSrf08
//
// MIT License
// Copyright(c) 2009 Zach Foresta
// Copyright(c) 2012 Leo Colombaro
//

#ifndef SonarSRF08_h
#define SonarSRF08_h

#include "Arduino.h"

class SonarSRF08
{
public:
    void connect();
    void sendCommand(int commandRegister, int address, int command, int gainRegister, int rangeLocation);
    void setUnit(int commandRegister, int address, char units, int gainRegister, int rangeLocation);
    void setRegister(int address, int thisRegister);
    int  readData(int address, int numBytes);
    void changeAddress(int commandRegister, int NEW_ADDRESS, int gainRegister, int rangeLocation);

private:
    // int _pin1;
    // int _pin2;
};

#endif