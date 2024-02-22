#include "SwissTime.hpp"

SwissTime::SwissTime(int wakeupdelay_ms)  : wakeupdelay_cnt(0), awakeCountPerDay(3), reconnectionMinuteTime(60), wifiTimeError(false), initializied(false), 
                                            wakeupdelay_ms(wakeupdelay_ms), configPortalTimeout(120), connectTimeout(30), wifi(configPortalTimeout,connectTimeout)
{
    /* Configuration of NTP */
    configTime(MY_TZ, MY_NTP_SERVER);
}

bool SwissTime::getTime() {
    bool error = false;
    
    Serial.print("TIME: get SwissTime");

    if(initializied == false) {
        error = getTimeFromWifi();
        //awaitNextMinuteBoundary();
        initializied = true;
        Serial.println("TIME: Initial get time from wifi");
    } else {
            if(wakeupdelay_cnt >= ((24*60)/awakeCountPerDay)) {
                    error = getTimeFromWifi();
                    wifiTimeError = error;
                    wakeupdelay_cnt = 0;
                    Serial.print("TIME: Get Time from wifi after timeout");
                    if(wifiTimeError == true) {
                        error = getTimeFromLocalCounter();
                        wifiTimeError = false; // Error handeld
                        Serial.println("TIME: Calculate time after failed wifi connection");
                    }
            } else {
                error = getTimeFromLocalCounter();    
                Serial.print("TIME: Calculate time");
            }
    }

    wakeupdelay_cnt++;
    return error;
}

bool SwissTime::awaitNextMinuteBoundary(void) {
    if(s==0) {
        wakeupdelay_ms = 0;
    } else {
        wakeupdelay_ms = (60-s)*1000;
    }

    Serial.print("TIME: awaitNextMinuteBoundary: ");
    Serial.println(wakeupdelay_ms/1000);

    if(wakeupdelay_ms != 0) {
        delay(wakeupdelay_ms);
        return true;
    } else {
        return false;
    }

    /*if(time_to_wait!=0) {
        
        s = 0;
        m++;
        if(m>=60) {
            m=0;
            h++;
        }
        if(h>=24) {
            h=0;
        }
        return true;;
    }
    return false;
    
    Serial.print(h);
    Serial.print("h");
    Serial.print(m);
    Serial.print("m");
    Serial.print(s);
    Serial.print("s");
    Serial.println("");*/
    
}

bool SwissTime::getTimeFromWifi()
{   
    bool error = wifi.connectToWifi();
    if (error == false) {
        delay(1000);
        time(&now);
        localtime_r(&now, &tm_data);
        s = tm_data.tm_sec;
        m = tm_data.tm_min;
        h = tm_data.tm_hour;

        
        Serial.println("Time now:");
        Serial.print(h);
        Serial.print("h");
        Serial.print(m);
        Serial.print("m");
        Serial.print(s);
        Serial.print("s");
        Serial.println("");

        if (h >= 24)
        {
            h = 0;
        }
        wifi.disconnectFromWifi();
        return false;
    } else {
        return true;
    }
}

bool SwissTime::getTimeFromLocalCounter() {
    int64_t time_passed = 0;
    int64_t inaccuracy_timout = 1132;
    // Determin passed time
    if(wifiTimeError == false) {
        time_passed = wakeupdelay_ms/1000 + inaccuracy_timout/1000;
    } else {
        time_passed = wakeupdelay_ms/1000 + configPortalTimeout + connectTimeout + inaccuracy_timout/1000;
    }

    if(time_passed>=60) {
        int64_t sec_in_min = (time_passed/60);
        m += sec_in_min;
        int64_t restSec = time_passed-(sec_in_min*60);
        s += restSec;
    } else {
        s += time_passed;
    }
    if(s>=60) {
        m++;
        s=s-60;
    }

    if(m>=60) {
        h++;
        m=m-60;
    }

    if(h>24) {
        h=h-24;
    }

    Serial.print(h);
    Serial.print("h");
    Serial.print(m);
    Serial.print("m");
    Serial.print(s);
    Serial.print("s");
    Serial.println("");
    return false;
}