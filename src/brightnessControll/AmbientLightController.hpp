#ifndef BRIGHTNESSCONTROLLER_HPP
#define BRIGHTNESSCONTROLLER_HPP

#include "Arduino.h"
#include "ALSPT19.hpp"

class AmbientLightController
{

    public:
        AmbientLightController();
        int getLedBrightness(void);
        int getminLedBrightness(void);
        int getmaxLedBrightness(void);     
    private:
        ALSPT19 alspt19;

        uint16_t MIN_LED_BRIGHTNESS;                         // Min LED Brightness
        uint16_t MAX_LED_BRIGHNTESS;                         // Max LED Brightness

};

#endif
