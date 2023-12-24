#ifndef WIFIHOST_HPP
#define WIFIHOST_HPP
#include "Arduino.h"
#include <WifiClientSecure.h>
#include <WiFiManager.h>


class wifiHost
{
public:
    //wifiHost();
    wifiHost(int configPortalTimeout, int connectTimeout);
    bool connectToWifi(void);
    bool disconnectFromWifi(void);

private:
    WiFiManager manager; 
    int this_configPortalTimeout;
    int this_connectTimeout;
    //const char*  ssid = "Salt_2GHz_159505";
    //const char* password = "MuUY33L6SERtXG4CDT";

};
#endif