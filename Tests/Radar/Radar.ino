#define SENSOR_PIN D5

void setup() {
  initSerial();
  initLed();

  pinMode(SENSOR_PIN, INPUT);

  turnLedOn();
  delay(1000);
  turnLedOff();
  delay(100);
}

void loop() {
  /*
  turnLedOn();
  delay(4000);
  turnLedOff();
  delay(1000);*/
  int sensorValue = digitalRead(SENSOR_PIN);
  Serial.println(sensorValue);
  if (sensorValue == HIGH) {
    turnLedOn();
  } else {
    turnLedOff();
  }

  delay(200);
}

void initLed() {
  pinMode(BUILTIN_LED, OUTPUT);
}

void initSerial() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Initializing serial connection DONE.");
}

void turnLedOn() {
  digitalWrite(BUILTIN_LED, LOW);  
}

void turnLedOff() {
  digitalWrite(BUILTIN_LED, HIGH);
}
