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
    WiFiSet(const int exitPin_);
    WiFiSet(char *ssid, char *pass);
    WiFiSet(char *ssid, char *pass, const int exitPin_);
    // Mutators
    void setSSID(char *ssid);
    void setPass(char *pass);
    void setKeyIndex(int keyIndex);
    void setExitPin(const int exitPin_);
    int getKeyIndex() const;
    // Methods
    bool checkWifiModule();
    bool checkFirmwareVersion();
    bool exit();
    void connectNoEncryption();
    void connectWEP();
    void connectWPA();
    void scanNetworks();
protected:
    // Accessors
    char *getSSID();
    char *getPass(); 
    int getExitPin() const;
private:
    char ssid[32];
    char pass[32];
    int status = WL_IDLE_STATUS;
    int keyIndex = 0; // your network key Index number (needed only for WEP)
    int exitPin;
};
#endif