#include "WiFi.h"

const char *ssid = "ESP32-AP";          // Name of the Wi-Fi network (SSID)
const char *password = "123456789";     // Password of the Wi-Fi network

void setup() {
  Serial.begin(115200);  

  // Configuration of the ESP32 as an Access Point
  WiFi.softAP(ssid, password);

  Serial.println("Access Point started!");
  Serial.print("IP of the AP: ");
  Serial.println(WiFi.softAPIP());  // Access Point IP
}

void loop() {
}
