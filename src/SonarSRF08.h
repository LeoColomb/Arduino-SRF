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

#ifndef SONARSRF08_H
#define SONARSRF08_H

#include "SonarSRF.h"

class SonarSRF08 : public SonarSRF
{
public:
    SonarSRF08(int address, int gainRegister = 0, int rangeLocation = 0)
        : SonarSRF(address, gainRegister, rangeLocation) {};
    uint8_t readLuminosity(void);
};

#endif // SONARSRF08_H
