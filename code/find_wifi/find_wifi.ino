#include "WiFi.h"

void setup() {
  Serial.begin(115200);
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("Scanning WiFi networks...");
  
  // WiFi.scanNetworks returns the number of networks found
  int n = WiFi.scanNetworks();
  
  if (n == 0) {
    Serial.println("No WiFi networks found.");
  } else {
    Serial.print(n);
    Serial.println(" networks found:");
    Serial.println("--------------------------------");
    
    for (int i = 0; i < n; ++i) {
      // Print SSID, RSSI, and encryption type for each network
      Serial.print("SSID: ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" | RSSI: ");
      Serial.print(WiFi.RSSI(i));
      Serial.print(" dBm | Encryption: ");
      // The encryption type is returned as an enum, you can print the type for more detail
      Serial.println(WiFi.encryptionType(i));
    }
  }
}

void loop() {
  // Nothing to do in the loop for a one-time scan
  delay(5000); 
}