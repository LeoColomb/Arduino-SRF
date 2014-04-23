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
#include <SonarSRF08.h>

#define leftAddress ( 0xF2 >> 1)
#define rightAddress ( 0xE0 >> 1)
#define mainAddress ( 0xF8 >> 1)
SonarSRF02 LeftSonar;
SonarSRF02 RightSonar;
SonarSRF08 MainSonar;

char unit = 'c'; // 'i' for inches, 'c' for centimeters, 'm' for micro-seconds

void setup() {
    Serial.begin(115200);

    LeftSonar.connect(leftAddress);
    Serial.println("Left SRF02 US-Sensor ");
    Serial.println(LeftSonar.getSoft());

    RightSonar.connect(rightAddress);
    Serial.println("Right SRF02 US-Sensor ");
    Serial.println(RightSonar.getSoft());

    MainSonar.connect(mainAddress);
    Serial.println("Main SRF08 US-Sensor ");
    Serial.println(MainSonar.getSoft());
}

void loop() {
    float sensorReading = 0;

    sensorReading = LeftSonar.getRange(unit);
    // print out distance
    Serial.print("Distance from left: ");
    Serial.print(sensorReading);
    Serial.print(" ");
    Serial.print(unit);
    Serial.println();

    sensorReading = RightSonar.getRange(unit);
    // print out distance
    Serial.print("Distance from right: ");
    Serial.print(sensorReading);
    Serial.print(" ");
    Serial.print(unit);
    Serial.println();

    sensorReading = MainSonar.getRange(unit);
    // print out distance
    Serial.print("Distance from main: ");
    Serial.print(sensorReading);
    Serial.print(" ");
    Serial.print(unit);
    Serial.println();
}
