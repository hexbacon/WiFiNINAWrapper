
# WiFiWrapper

Simple WiFi Wrapper for WiFiNINA Arduino. Implements the most useful funcionality for ease of use in any Arduino microconterler that supports the WiFiNINA package.

## Documentation

To deploy the wrapper, include on your project file

```c++
  #include "WiFiSet"
```

1. Start by creating WiFiSet object

```c++
    WiFiSet myWifi;
```

2. Starting with parametrized constructor

```c++
    char ssid[] = "MY NETWORK";
    char pass[] = "MY PASSWORD";
    WiFiSet myWifi(ssid, pass);
```

3. Set the SSID if using default constructor

```c++
    myWifi.setSSID(char *ssid);
```

4. Set the Password if using default constructor

```c++
    myWifi.setPass(char *pass);
```

5. Set key index if using WEP connection

```c++
    myWifi.setKeyIndex(int keyIndex);
```

6. Get key index when needed

```c++
    myWifi.getKeyIndex();
```

7. Check for module existance

```c++
    bool doesExist = myWifi.checkWifiModule();
```

8. Check for Firmware version

```c++
    bool firmware = myWifi.checkFirmwareVersion();
```

9. Connect to network

```c++
    // No Encryption
    myWifi.connectNoEncryption();
    // WEP Encryption
    myWifi.connectWEP();
    // WPA Encryption
    myWifi.connectWPA();
```

10. Terminates any connection
    
``` c++
    myWifi.exit()
```
