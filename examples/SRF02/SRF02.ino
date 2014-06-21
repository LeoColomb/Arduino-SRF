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

#include <Wire.h>
#include <SonarSRF02.h>

#define LEFT_02_ADDRESS (0xF2 >> 1)
#define RIGHT_02_ADDRESS (0xE0 >> 1)
SonarSRF02 LeftSonar;
SonarSRF02 RightSonar;

char unit = 'c'; // 'i' for inches, 'c' for centimeters, 'm' for micro-seconds

void setup() {
    Serial.begin(115200);

    LeftSonar.connect(LEFT_02_ADDRESS);
    isConnected("SRF02-left", LeftSonar.getSoft());

    RightSonar.connect(RIGHT_02_ADDRESS);
    isConnected("SRF02-right", RightSonar.getSoft());
}

void loop() {
    float sensorReading = 0;

    sensorReading = LeftSonar.getRange(unit);
    distance("left", sensorReading);

    sensorReading = RightSonar.getRange(unit);
    distance("right", sensorReading);
}

// Print out distance
void distance(String reference, int sensorReading) {
    Serial.print("Distance from " + reference + ": ");
    Serial.print(sensorReading);
    Serial.print(unit);
    Serial.println();
}

// Print out distance
void isConnected(String reference, int sensorSoft) {
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
