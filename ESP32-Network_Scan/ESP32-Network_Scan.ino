#include "WiFi.h"

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_MODE_STA);  // Set the ESP32 to "station mode" (acts as a Wi-Fi client)
    WiFi.disconnect();  // Disconnect from any previously connected Wi-Fi networks (prevents issues)
}

void loop() {
    delay(500);
    
    Serial.println("-----------------------------------------------------------------------------------");
    Serial.println("Scanning for WiFi networks...");

    int numNetworks = WiFi.scanNetworks();  // Perform a Wi-Fi scan and return the number of detected networks

    // Iterate through all detected Wi-Fi networks
    for (int i = 0; i < numNetworks; i++) {
        Serial.printf("SSID: %s | MAC: %s | Channel: %d | RSSI: %d dBm\n",
                      WiFi.SSID(i).c_str(),  // Wi-Fi network name (SSID)
                      WiFi.BSSIDstr(i).c_str(),  // Router's MAC address (BSSID)
                      WiFi.channel(i),  // Wi-Fi channel the network is operating on
                      WiFi.RSSI(i));  // Signal strength (RSSI) in dBm (closer to 0 means a stronger signal)
    }

    Serial.println("Scan complete.");
    Serial.println("-----------------------------------------------------------------------------------");
}
