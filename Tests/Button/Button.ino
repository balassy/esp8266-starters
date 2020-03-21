// 3.3V => button =>  D8

void setup() {
  initSerial();
  initLed();
}

void loop() {
  int buttonState = digitalRead(D8);
  if(buttonState == HIGH) {
    Serial.println("HIGH");
    digitalWrite(BUILTIN_LED, LOW);
  } 
  else {
    Serial.println("LOW");
    digitalWrite(BUILTIN_LED, HIGH);
  }

  delay(300);
}

void initLed() {
  pinMode(BUILTIN_LED, OUTPUT);
}

void initButton() {
  pinMode(D8, INPUT);
}

void initSerial() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Initializing serial connection DONE.");
}
