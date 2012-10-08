/*
	SonarSRF08.h - library for controlling SRF0x sonar sensors
		By Zach Foresta April 10, 2009
		By Leo Colomb May 10, 2012
        By Philipp A. Mohrenweiser Okt 08 2012
*/

#ifndef SonarSRF02_h
#define SonarSRF02_h

#include "Arduino.h"
#include "SonarSRF.h"

class SonarSRF02 : public SonarSRF 
{
public:
    void waitForCompletion();
};

#endif
