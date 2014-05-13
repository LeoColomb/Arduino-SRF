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
#include <SonarSRF08.h>

#define LEFT_02_ADDRESS (0xF2 >> 1)
#define RIGHT_02_ADDRESS (0xE0 >> 1)
#define MAIN_08_ADDRESS (0xF8 >> 1)
SonarSRF08 MainSonar;

char unit = 'c'; // 'i' for inches, 'c' for centimeters, 'm' for micro-seconds

void setup() {
    Serial.begin(9600);

    MainSonar.connect(MAIN_08_ADDRESS);
    isConnected("SRF08", MainSonar.getSoft());
}

void loop() {
    float sensorReading = 0;
    sensorReading = MainSonar.getRange(unit);
    distance("main", sensorReading);
}

// Print out distance
void distance(String reference, int sensorReading) {
    Serial.print("Distance from " + reference + ": ");
    Serial.print(sensorReading);
    Serial.print(" ");
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
