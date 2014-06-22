Arduino library for SRF0X
=========================
[![Latest Release](http://img.shields.io/github/release/LeoColomb/Arduino-SRF.svg?style=flat)](https://github.com/LeoColomb/Arduino-SRF/releases)
[![Build for Arduino](http://img.shields.io/badge/build%20for-arduino-00979c.svg?style=flat)](http://arduino.cc/)

This lib wants to give a quick shot on differences for usage of SRF 02 and 08 atm.
You can easily use it like in the example

Get more information at [Arduino site](http://arduino.cc/playground/Main/SonarSrf08)

Requirements
------------
* An [Arduino board](http://arduino.cc/)
* An SRF sensor
* Wire library (include in the Arduino Software)

Assemblage
----------
![schema](schema.png)

Board | I2C / TWI pins
:-----|:------
Uno, Ethernet | A4 (SDA), A5 (SCL)
Mega2560 | 20 (SDA), 21 (SCL)
Leonardo | 2 (SDA), 3 (SCL)
Due | 20 (SDA), 21 (SCL), SDA1, SCL1

License
-------
Project licensed under the [MIT License](LICENSE).
