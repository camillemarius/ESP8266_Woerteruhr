#ifndef ALSPT19_HPP
#define ALSPT19_HPP

#include "Arduino.h"

class ALSPT19
{

    public:
        ALSPT19();
        int getIlluminance();
        int getMinIlluminance();
        int getMaxIlluminance();
    
    private:
        void calculateIlluminance();

    private: 
        int16_t min_illuminance;
        int16_t max_illuminance;
        int16_t actuall_illuminance;

        //const int8_t  alsPower      = sensorPowerPin;  // Power pin
        //const int8_t  alsData       = A4;              // The ALS PT-19 data pin
        const int8_t  alsSupply     = 3.3;  // The ALS PT-19 supply power voltage
        const int8_t  alsResistance = 10;   // The ALS PT-19 loading resistance (in kΩ)
        const uint8_t alsNumberReadings = 10;
};

#endif
