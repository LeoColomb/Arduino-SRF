/*
	SonarSRF.h - base library for controlling SRF0x sonar sensors
        Sensor connections:
        SDA - Analog pin 4
        SCL - Analog pin 5
    By Zach Foresta April 10, 2009
    By Leo Colomb May 10, 2012
    By Philipp A. Mohrenweiser Okt 08 2012
*/

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
