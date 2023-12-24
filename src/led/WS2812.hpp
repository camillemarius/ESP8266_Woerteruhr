#ifndef WS2812_h
#define WS2812_h

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class WS2812
{
    public:
        WS2812(int led_cnt);
        void ws2812_init();
        void ws2812_array_set(int data[]);
        void prefix();
        void min(int m);
        void hour(int h);
        void ws2812_refresh(int s, int m, int h);
        void rainbow(uint8_t wait);
        void dimm(uint8_t wait);
        void preview();
        void regulate_brightness();
        void all_off();
        uint32_t Wheel(byte WheelPos);

    private:
        WS2812(Adafruit_NeoPixel *m_strip)
            : strip(m_strip)
        {
        }
        Adafruit_NeoPixel *strip;

        #include <clocks/seislerdeutsch_marlyse.h>
        #define LED_PIN D1
        int led_cnt;

        #define BRIGHTNESS 15 // (0 - 255)
        #define white 0xFFFFFFFF
        #define off   0x00000000
};

#endif