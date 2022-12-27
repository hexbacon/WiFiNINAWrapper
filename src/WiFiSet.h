#ifndef WiFiSet_h
#define WiFiSet_h
#include <Arduino.h>
#include <WiFiNINA.h>
#include <SPI.h>

class WiFiSet
{
public:
    // Constructor
    WiFiSet();
    WiFiSet(char *ssid, char *pass);
    // Mutators
    void setSSID(char *ssid);
    void setPass(char *pass);
    void setKeyIndex(int keyIndex);
    int getKeyIndex();
    // Methods
    bool checkWifiModule();
    bool checkFirmwareVersion();
    void connectNoEncryption();
    void connectWEP();
    void connectWPA();
    void scanNetworks();
protected:
    // Accessors
    char *getSSID();
    char *getPass(); 
private:
    char ssid[32];
    char pass[32];
    int status = WL_IDLE_STATUS;
    int keyIndex = 0; // your network key Index number (needed only for WEP)
};
#endif