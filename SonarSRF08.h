/*
	SonarSRF08.h - library for controlling SRF08 sonar sensors
		By Zach Foresta April 10, 2009
		By Leo Colomb May 10, 2012
*/

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