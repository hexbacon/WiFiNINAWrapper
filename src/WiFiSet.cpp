#include "WiFiSet.h"

// Cosntructor
WiFiSet::WiFiSet()
{
    // Do nothing
}

WiFiSet::WiFiSet(char *ssid, char *pass)
{
    setSSID(ssid);
    setPass(pass);
}

// Mutators
void WiFiSet::setSSID(char *ssid)
{
    strcpy(this->ssid, ssid);
}

void WiFiSet::setPass(char *pass)
{
    strcpy(this->pass, pass);
}

void WiFiSet::setKeyIndex(int keyIndex)
{
    this->keyIndex = keyIndex;
}

// Accessors
char *WiFiSet::getSSID()
{
    return ssid;
}

char *WiFiSet::getPass()
{
    return pass;
}

int WiFiSet::getKeyIndex()
{
    return keyIndex;
}

// Methods
bool WiFiSet::checkWifiModule()
{
    // Check for the presence of the shield
    if (WiFi.status() == WL_NO_SHIELD)
    {
        Serial.println("WiFi shield not present");
        // don't continue
        return false;
    }
    else if(WiFi.status() == WL_NO_MODULE)
    {
        Serial.println("WiFi module not present");
        // don't continue
        return false;
    }
    return true;
}

bool WiFiSet::checkFirmwareVersion()
{
    // Check for the firmware version
    String firmware = WiFi.firmwareVersion();
    if (firmware < WIFI_FIRMWARE_LATEST_VERSION)
    {
        Serial.println("Please upgrade the firmware");
        // don't continue
        return false;
    }
    return true;
}

void WiFiSet::connectNoEncryption()
{
    // attempt to connect to WiFi network
    while (status != WL_CONNECTED)
    {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(ssid);
        // wait 10 seconds for connection:
        delay(10000);
    }
    Serial.println("Connected to wifi");
}

void WiFiSet::connectWEP()
{
    // attempt to connect to WiFi network
    while (status != WL_CONNECTED)
    {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(ssid, keyIndex, pass);
        // wait 10 seconds for connection:
        delay(10000);
    }
    Serial.println("Connected to wifi");
}

void WiFiSet::connectWPA()
{
    // attempt to connect to WiFi network
    while (status != WL_CONNECTED)
    {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(ssid, pass);
        // wait 10 seconds for connection:
        delay(10000);
    }
    Serial.println("Connected to wifi");
}

void WiFiSet::scanNetworks()
{
    // scan for nearby networks:
    Serial.println("** Scan Networks **");
    int numSsid = WiFi.scanNetworks();
    if (numSsid == -1)
    {
        Serial.println("Couldn't get a wifi connection");
        while (true)
        {
            delay(1000);
        }
    }

    // print the list of networks seen:
    Serial.print("number of available networks:");
    Serial.println(numSsid);

    // print the network number and name for each network found:
    for (int thisNet = 0; thisNet < numSsid; thisNet++)
    {
        Serial.print(thisNet);
        Serial.print(") ");
        Serial.print(WiFi.SSID(thisNet));
        Serial.print("\tSignal: ");
        Serial.print(WiFi.RSSI(thisNet));
        Serial.print(" dBm");
        Serial.print("\tEncryption: ");
        Serial.println(WiFi.encryptionType(thisNet));
        delay(10);
    }
}