#include <ESP8266WiFi.h>       // To connect to the WiFi network.

void setup() {
  Serial.begin(74880);
  Serial.println();
  Serial.println("Starting....");

  Serial.setTimeout(2000);

  // Wait for serial to initialize.
  while(!Serial) { }  

  // This does not work with NodeMCU, becuase the LED_BUILTIN is connected to GPIO16,
  // and Deep Sleep needs to connect GPIO16 to RST.
  // On Wemos D1 Mini LED_BUILTIN is GPIO2, so this flashing works.
  Serial.println("Flashing the LED...");
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

  Serial.println("Getting MAC address...");
  Serial.println(WiFi.macAddress());

  Serial.println("Going to sleep...");
  pinMode(D0, WAKEUP_PULLUP);
  ESP.deepSleep(10e6);
}

void loop() {
}
