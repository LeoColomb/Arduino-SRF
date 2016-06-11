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

#include "SonarSRF.h"

/// <summary>
/// Initiates the connection with the sensor and start I2C bus
/// </summary>
/// <param name="address">I2C Address</param>
/// <param name="gainRegister">SRF Location 1</param>
/// <param name="rangeLocation">SRF Location 2</param>
void SonarSRF::begin(int address, int gainRegister, int rangeLocation)
{
    _address = address;
    _gainRegister = gainRegister;
    _rangeLocation = rangeLocation;
    Wire.begin();
}

/// <summary>
/// Sets Units for display / storage
/// </summary>
/// <remarks>
/// * 'i' for inches
/// * 'c' for centimeters
/// * 'm' for microseconds
/// </remarks>
/// <param name="unit">Unit used</param>
void SonarSRF::startRanging(char unit)
{
    switch (unit)
    {
    case 'i':
        sendCommand(INCHES);
        break;
    case 'c':
        sendCommand(CENTIMETERS);
        break;
    case 'm':
        sendCommand(MICROSECONDS);
        break;
    default:
        Serial.println("Invalid units entered... using micro-seconds");
        sendCommand(MICROSECONDS);
    }
}

/// <summary>
/// Communicates with Sonar to send commands
/// </summary>
/// <param name="command">SRF Command</param>
/// <param name="addressRegister">SRF Location 0</param>
/// <seealso cref="connect"/>
void SonarSRF::sendCommand(int command, int addressRegister)
{
    // start I2C transmission
    Wire.beginTransmission(_address);
    Wire.write(byte(addressRegister));
    if (command != 0)
    {
        // send command
        Wire.write(byte(command));
        if (_gainRegister && _rangeLocation)
        {
            Wire.write(byte(_gainRegister)); // SRF Location 1
            Wire.write(byte(_rangeLocation)); // SRF Location 2
        }
    }
    // end I2C transmission
    Wire.endTransmission();
}

/// <summary>
/// Read data from register return result
/// </summary>
/// <param name="unit">Unit used</param>
/// <param name="andStart"></param>
/// <returns>The range number (two bytes)</returns>
/// <seealso cref="startRanging"/>
int SonarSRF::getRange(char unit, bool andStart)
{
    if (andStart)
    {
        startRanging(unit);
        waitForCompletion();
    }
    sendCommand(0, RANGE_REGISTER);
    Wire.requestFrom(_address, 2);
    // wait for two bytes to return
    while (Wire.available() < 2); // wait for result
    // read the two bytes, and combine them into one int
    byte highByte = Wire.read(); // Stores high byte from ranging
    byte lowByte = Wire.read(); // Stored low byte from ranging
    return (int)((highByte << 8) + lowByte);
}

/// <summary>
/// Wait for completion
/// </summary>
void SonarSRF::waitForCompletion()
{
    while (getVersion() == -1)
    {
        delay(1);
    }
}

/// <summary>
/// Get software revision
/// </summary>
/// <returns>The software revision (one byte)</returns>
int SonarSRF::getVersion()
{
    sendCommand(0, SOFTWARE_REVISION);
    Wire.requestFrom(_address, 1); // Request 1 byte
    while (Wire.available() < 0); // While byte available
    return (int)(Wire.read());
}

/// <summary>
/// Set a new address
/// </summary>
/// <remarks>
/// The address given in Arduino 7bit has to be converted back into SRF 8bit
/// newAddress can be set to any of E0, E2, E4, E6, E8, EA, EC, EE, F0, F2,
/// F4, F6, F8, FA, FC, FE.
/// </remarks>
/// <param name="newAddress">The new address</param>
void SonarSRF::setAddress(int newAddress)
{
    sendCommand(0xA0);
    sendCommand(0xAA);
    sendCommand(0xA5);
    sendCommand(newAddress << 1);
}
