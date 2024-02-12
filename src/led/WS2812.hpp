#ifndef WS2812_h
#define WS2812_h

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include "brightness/lightMapping.hpp"

class WS2812
{ 
    public:
        void initWS2812();
        WS2812(int led_cnt);
        void showTime(int s, int m, int h);
        void advertisingAnimation();
        void allOff();

    private:
        void showMin(int m);
        void showHour(int h);
        void prefix();
        void adjustBrightness();
        void setPixelColorArrayMap(int data[]);
        
        void dimOn(int finalBrightness);
        void rainbowWheel(uint8_t wait);
        uint32_t colourWheel(byte WheelPos);
        void showNoInternet(void);
   

    private:
        WS2812(Adafruit_NeoPixel *m_strip)
            : strip(m_strip) 
            {

            }
        Adafruit_NeoPixel *strip;
        
        LightMapping lightMap;;

        //#include <clocks/seislerdeutsch_marlyse.h>
        #include <clocks/berndeutsch_jaya.h>
        #define LED_PIN D1
        int led_cnt;

        #define white 0xFFFFFFFF
        #define off   0x00000000
};

#endif
