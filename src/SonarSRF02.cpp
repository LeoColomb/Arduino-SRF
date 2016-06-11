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

#include "SonarSRF02.h"

/// <summary>
/// Wait for completion
/// </summary>
/// <remarks>
/// Completion wait on SRF02 takes 66ms, std way to check register 0 doesn't
/// seem to work with software revision 6.
/// </remarks>
void SonarSRF02::waitForCompletion()
{
    delay(66);
}
