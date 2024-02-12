#ifndef BRIGHTNESSCONTROLLER_HPP
#define BRIGHTNESSCONTROLLER_HPP

#include "Arduino.h"
#include "ALSPT19.hpp"

class LightMapping
{

    public:
        LightMapping();
        int mapIlluminanceToLEDBrightness();
    
    private:
        ALSPT19 alspt19;

};

#endif
