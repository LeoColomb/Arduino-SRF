/*
	SonarSRF08.h - library for controlling SRF08 sonar sensors
		By Zach Foresta April 10, 2009
		By Leo Colomb May 10, 2012
        By Philipp A. Mohrenweiser Okt 08 2012
*/

#ifndef SonarSRF08_h
#define SonarSRF08_h

#include "SonarSRF.h"

class SonarSRF08 : public SonarSRF 
{
public:
    void startRanging(char unit);
};

#endif
