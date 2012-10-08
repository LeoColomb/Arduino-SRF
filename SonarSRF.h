/*
	SonarSRF.h - library for controlling SRF0x sonar sensors
		By Zach Foresta April 10, 2009
		By Leo Colomb May 10, 2012
        By Philipp A. Mohrenweiser Okt 08 2012
*/

#ifndef SonarSRF_h
#define SonarSRF_h

#include "Arduino.h"

class SonarSRF {
    public:
        void         connect(int address);
        virtual void startRanging(char unit);
        virtual int  getRange(char unit, bool andStart = true);
        int          getSoft();
        void         changeAddress(int NEW_ADDRESS);
    protected:
        int          getCommand(char unit);
        virtual void waitForCompletion() = 0;
        void         sendBasicCommand(int command);
        int          _address;
};

#endif
