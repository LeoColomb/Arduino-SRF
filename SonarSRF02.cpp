/*
    SonarSRF02.cpp - SRF02 sensor reader code
        By Zach Foresta Apr 2009
        By Leo Colomb May 2012
        By Philipp A. Mohrenweiser Okt 08 2012
*/

#include "SonarSRF02.h"
#include <Arduino.h>

/**
 * Completion wait on 02 takes 66ms, 
 * std way to check register 0 doesnt seem to work with software revision 6
 */
void SonarSRF02::waitForCompletion(){
    delay(66);
}
