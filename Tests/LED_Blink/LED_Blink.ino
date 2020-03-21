void setup() {
  initSerial();
  initLed();
}

void loop() {
  digitalWrite(BUILTIN_LED, HIGH);
  delay(1000);
  digitalWrite(BUILTIN_LED, LOW);
  delay(1000);
}

void initLed() {
  pinMode(BUILTIN_LED, OUTPUT);
}

void initSerial() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Initializing serial connection DONE.");
}
