#include "WifiHost.hpp"

wifiHost::wifiHost(int configPortalTimeout, int connectTimeout) 
:this_configPortalTimeout(configPortalTimeout), this_connectTimeout(connectTimeout) {

}

bool wifiHost::connectToWifi(void) {
    //manager.setConfigPortalBlocking(true);
    manager.setConfigPortalTimeout(this_configPortalTimeout);
    manager.setConnectTimeout(this_connectTimeout);
    if(manager.autoConnect("Clocktwo")) {
        return false;
    }
    Serial.println("There is no Wifi Connection, not even afer 90 sec Timeout");
    return true;
}

bool wifiHost::disconnectFromWifi(void) {
    return manager.disconnect();
}
