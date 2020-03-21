// Platform libraries.
#include <ESP8266WiFi.h>

// Third-party libraries.
#include <WiFiManager.h>  // To manage network configuration and connection.

const char* WIFI_AP_SSID = "NewBoard";     // The name of the wireless network to create if cannot connect using the previously saved credentials.
const char* WIFI_AP_PASSWORD = "esp8266";  // The password required to connect to the wireless network used to configure the network parameters.

WiFiManager wifiManager;

void setup() {
  initSerial();
  initNetwork();
  initLed();
}

void loop() {
  digitalWrite(BUILTIN_LED, HIGH);
  delay(1000);
  digitalWrite(BUILTIN_LED, LOW);
  delay(1000);

  readBatteryVoltage();
}

void initLed() {
  pinMode(BUILTIN_LED, OUTPUT);
}

void initSerial() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Initializing serial connection DONE.");
}

void initNetwork() {
  Serial.printf("Initializing connection to the network with MAC address %s using WiFiManager (SSID: %s)...", WiFi.macAddress().c_str(), WIFI_AP_SSID);
  wifiManager.autoConnect(WIFI_AP_SSID, WIFI_AP_PASSWORD);
  Serial.printf("WiFi connected. IP address: %s, MAC address: %s\n", WiFi.localIP().toString().c_str(), WiFi.macAddress().c_str());
}

void readBatteryVoltage() {
  float calib_factor = 5.28; // change this value to calibrate the battery voltage
  unsigned long raw = analogRead(A0);
  float volt = raw * calib_factor/1024; 
  
  Serial.print( "Voltage = ");
  Serial.print(volt, 2); // print with 2 decimal places
  Serial.println (" V");
}
