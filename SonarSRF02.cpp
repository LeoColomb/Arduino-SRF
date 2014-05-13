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

#include "SonarSRF02.h"

void SonarSRF02::waitForCompletion()
{
    delay(66);
    // Completion wait on 02 takes 66ms,
    // std way to check register 0 doesnt seem to work with software revision 6
}
