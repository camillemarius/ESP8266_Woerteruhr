#ifndef BRIGHTNESSCONTROLLER_HPP
#define BRIGHTNESSCONTROLLER_HPP

#include "Arduino.h"
#include "ALSPT19.hpp"

class LightMapping
{

    public:
        LightMapping();
        int mapIlluminanceToLEDBrightness();
        int getminLedBrightness();
        int getmaxLedBrightness();     
    private:
        ALSPT19 alspt19;

        const uint16_t MIN_LED_BRIGHTNESS = 50;                         // Min LED Brightness
        const uint16_t MAX_LED_BRIGHNTESS = 250;                         // Max LED Brightness

};

#endif
