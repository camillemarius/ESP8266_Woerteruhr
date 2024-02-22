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
};

#endif
