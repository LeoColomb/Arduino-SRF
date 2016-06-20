//
// SonarSRF02
// Arduino Library for controlling SRF sonar sensors
// http://www.arduino.cc/playground/Main/SonarSrf08
//
// MIT License
// Copyright(c) 2009 Zach Foresta
// Copyright(c) 2012 Philipp A. Mohrenweiser
// Copyright(c) 2012-2016 Leo Colombaro
//

#include <Wire.h>
#include <SonarSRF02.h>

#define LEFT_02_ADDRESS (0xF2 >> 1)
#define RIGHT_02_ADDRESS (0xE0 >> 1)
SonarSRF02 LeftSonar(LEFT_02_ADDRESS);
SonarSRF02 RightSonar(RIGHT_02_ADDRESS);

char unit = 'c'; // 'i' for inches, 'c' for centimeters, 'm' for micro-seconds

void setup()
{
  Serial.begin(115200);

  LeftSonar.begin();
  isConnected("SRF02-left", LeftSonar.readVersion());

  RightSonar.begin();
  isConnected("SRF02-right", RightSonar.readVersion());
}

void loop()
{
  int sensorReading = 0;

  sensorReading = LeftSonar.readRange(unit);
  distance("left", sensorReading);

  sensorReading = RightSonar.readRange(unit);
  distance("right", sensorReading);
}

// Print out distance
void distance(String reference, int sensorReading)
{
  Serial.print("Distance from " + reference + ": ");
  Serial.print(sensorReading);
  Serial.print(unit);
  Serial.println();
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
    Serial.println("Sensor " + reference + " not detected");
  }
}
