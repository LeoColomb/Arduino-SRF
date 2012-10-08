/*
* SRF0X.ino - example interfacing with sonar sensor SRF02 and SRF08
*	library uses Wire.h 
*		SDA - Analog Pin 4
*		SCL - Analog Pin 5
*
* Authors:
*	- Zach Foresta - Foureza87@yahoo.com (April 2009)
*	- Leo Colomb - @LeoColomb (May 2012)
*   - Philipp A. Mohrenweiser @phiamo (Okt 2012)
*
* For component setup - http://www.arduino.cc/playground/Main/SonarSrf08
*/

#include <Wire.h>
#include <SonarSRF02.h>
#include <SonarSRF08.h>


#define leftAddress ( 0xF2 >> 1) // I2C-BUS-Adresse des SRF02. Da der Arduino eine 7-Bit Adresse erwartet, muss ein Bit nach rechts geschoben werden.
#define rightAddress ( 0xE0 >> 1) // I2C-BUS-Adresse des SRF02. Da der Arduino eine 7-Bit Adresse erwartet, muss ein Bit nach rechts geschoben werden.
#define mainAddress ( 0xF8 >> 1) // I2C-BUS-Adresse des SRF02. Da der Arduino eine 7-Bit Adresse erwartet, muss ein Bit nach rechts geschoben werden.
SonarSRF02 LeftSonar;
SonarSRF02 RightSonar;
SonarSRF08 MainSonar;

char unit = 'c'; // 'i' for inches, 'c' for centimeters, 'm' for micro-seconds

void setup()
{
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

void loop ()
{
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
