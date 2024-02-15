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
        void setBrightnessFor(int ledIndex, uint8_t brightness);
        void copyPrevPixelColorArrayMap();
        void copyActualPixelColorArrayMap();

        void dimOn(int finalBrightness);
        void dimNewlyTurnedOn(int finalBrightness);
        void dimOff(int actuallBrighntess);
        void rainbowWheel(uint8_t wait);
        uint32_t colourWheel(byte WheelPos);
        void showNoInternet(void);
   

    private:
        WS2812(Adafruit_NeoPixel *m_strip)
            : strip(m_strip) 
            {

            }
        Adafruit_NeoPixel *strip;
        
        LightMapping lightMap;
        uint32_t *prevPixelColors;
        uint32_t *actualPixelColors;

        //#include <clocks/seislerdeutsch_marlyse.h>
        #include <clocks/v2berndeutsch.h>
        #define LED_PIN D1 //GPIO5
        int led_cnt;
        int brightness;

        #define white 0xFFFFFFFF
        #define off   0x00000000
};

#endif
