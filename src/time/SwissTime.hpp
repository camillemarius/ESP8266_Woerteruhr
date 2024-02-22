#ifndef SwissTime_HPP
#define SwissTime_HPP

#include "Arduino.h"
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include "wifiHost.hpp"

class SwissTime
{
    public:
        uint32_t  h, m, s;

        SwissTime(int wakeupdelay_ms);
        bool getTime();
        bool getTimeFromWifi();  
        bool getTimeFromLocalCounter();
        bool awaitNextMinuteBoundary(void);

    private:
        #define MY_NTP_SERVER "at.pool.ntp.org"       
        #define MY_TZ "CET-1CEST,M3.5.0/02,M10.5.0/03"  

        int wakeupdelay_cnt;
        int awakeCountPerDay;
        int reconnectionMinuteTime;
        bool wifiTimeError;
        bool initializied;
        int wakeupdelay_ms;
        int configPortalTimeout;
        int connectTimeout;

        time_t now;
        tm tm_data;
        wifiHost wifi;
        
};

#endif