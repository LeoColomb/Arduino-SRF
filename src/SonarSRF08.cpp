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

#include "SonarSRF08.h"

/// <summary>
/// Get luminosity captured by SRF08 sensor
/// </summary>
/// <returns>The luminosity (one byte)</returns>
uint8_t SonarSRF08::readLuminosity(void)
{
    writeUnit('i');
    delay(70);

    return (uint8_t)(read(LIGHT_SENSOR, 1));
}
