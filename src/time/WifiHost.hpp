#ifndef WIFIHOST_HPP
#define WIFIHOST_HPP
#include "Arduino.h"
#include <WifiClientSecure.h>
#include <WiFiManager.h>


class wifiHost
{
public:
    wifiHost(int configPortalTimeout, int connectTimeout);
    bool connectToWifi(void);
    bool disconnectFromWifi(void);

private:
    WiFiManager manager; 
    int this_configPortalTimeout;
    int this_connectTimeout;

};
#endif