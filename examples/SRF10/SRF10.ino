//
// SonarSRF10
// Arduino Library for controlling SRF sonar sensors
// http://www.arduino.cc/playground/Main/SonarSrf08
//
// MIT License
// Copyright(c) 2009 Zach Foresta
// Copyright(c) 2012 Philipp A. Mohrenweiser
// Copyright(c) 2012-2016 Leo Colombaro
//

#include <Wire.h>
#include <SonarSRF10.h>

#define MAIN_10_ADDRESS (0xF8 >> 1)
SonarSRF10 MainSonar(MAIN_10_ADDRESS);

char unit = 'c'; // 'i' for inches, 'c' for centimeters, 'm' for micro-seconds

void setup()
{
  Serial.begin(9600);

  MainSonar.begin();
  isConnected("SRF10", MainSonar.readVersion());
}

void loop()
{
  distance("SRF10", MainSonar.readRange(unit));
}

// Print out distance
void distance(String reference, int sensorReading)
{
  Serial.print("Distance from " + reference + ": ");
  Serial.print(sensorReading);
  Serial.println(unit);
}

// Print out distance
void isConnected(String reference, int sensorSoft)
{
  if (sensorSoft >= 0)
  {
    Serial.print("Sensor " + reference + " connected (");
    Serial.print(sensorSoft);
    Serial.println(")");
  }
  else
  {
    Serial.println("Sensor " + reference + " not detected...");
  }
}
