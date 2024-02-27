#ifndef SwissTime_HPP
#define SwissTime_HPP

#include "Arduino.h"
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include "WifiHost.hpp"

class SwissTime
{
    public:
        SwissTime(int wakeupdelay_ms);
        bool getTime();
        bool getTimeFromWifi();  
        bool getTimeFromLocalCounter();
        void awaitNextMinuteBoundary(void);
               
    public:
        uint32_t  h, m, s;

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
        WifiHost wifi;

 


        
};

#endif