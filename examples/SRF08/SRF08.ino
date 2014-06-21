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

#define MAIN_08_ADDRESS (0xF8 >> 1)
SonarSRF08 MainSonar;

// Setup Analogue Gain
// http://www.robot-electronics.co.uk/htm/srf08tech.html section "Analogue Gain"
#define GAIN_REGISTER 0x09
// Setup Range Location
// http://www.robot-electronics.co.uk/htm/srf08tech.html section "Changing the Range"
#define LOCATION_REGISTER 0x8C

char unit = 'c'; // 'i' for inches, 'c' for centimeters, 'm' for micro-seconds

void setup() {
    Serial.begin(9600);

    MainSonar.connect(MAIN_08_ADDRESS, GAIN_REGISTER, LOCATION_REGISTER);
    isConnected("SRF08", MainSonar.getSoft());
}

void loop() {
    float sensorReading = 0;
    sensorReading = MainSonar.getRange(unit);
    distance("sensor", sensorReading);
}

// Print out distance
void distance(String reference, int sensorReading) {
    Serial.print("Distance from " + reference + ": ");
    Serial.print(sensorReading);
    Serial.println(unit);
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
