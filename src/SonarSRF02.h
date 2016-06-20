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

#ifndef SONARSRF02_H
#define SONARSRF02_H

#include "SonarSRF.h"

class SonarSRF02 : public SonarSRF
{
public:
    SonarSRF02(int address, int gainRegister = 0, int rangeLocation = 0)
        : SonarSRF(address, gainRegister, rangeLocation) {};
    void waitForCompletion(void);
};

#endif // SONARSRF02_H
