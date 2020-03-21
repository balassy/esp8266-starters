/*
Wemos D1 mini/D1 lite 
Buzzer Shield example 
by Petr Lukas

Simple music, sound efects and cricket chirp sounds
*/

int buzzer=D5; //Buzzer control port, default D5

void setup() {
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  Serial.begin(115200);
  Serial.println("Buzzer Test...");
  
  musicTest();
  
  delay(1000);
  ohhh();
  
  delay(1000);
  uhoh(); 
  
  delay(1000);
  cricketChirp();
  cricketChirp();
  cricketChirp();
  cricketChirp();
}

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration, unsigned long pause) {
pinMode (_pin, OUTPUT );
analogWriteFreq(frequency);
analogWrite(_pin,500);
delay(duration);
analogWrite(_pin,0);
delay(pause);
}

void beep (int speakerPin, float noteFrequency, long noteDuration){
  int x;
  // Convert the frequency to microseconds
  float microsecondsPerWave = 1000000/noteFrequency;
  // Calculate how many milliseconds there are per HIGH/LOW cycles.
  float millisecondsPerCycle = 1000/(microsecondsPerWave * 2);
  // Multiply noteDuration * number or cycles per millisecond
  float loopTime = noteDuration * millisecondsPerCycle;
  // Play the note for the calculated loopTime.
  for (x=0;x<loopTime;x++)
  {
  digitalWrite(speakerPin,HIGH);
  delayMicroseconds(microsecondsPerWave);
  digitalWrite(speakerPin,LOW);
  delayMicroseconds(microsecondsPerWave);
  }
}

void musicTest(){
  delay(1000);
  tone(buzzer, 400, 600, 150);
  tone(buzzer, 400, 600, 150);
  tone(buzzer, 400, 600, 150);

  tone(buzzer, 320, 400, 80);
  tone(buzzer, 475, 150, 80);
  tone(buzzer, 400, 600, 100);

  tone(buzzer, 320, 400, 80);
  tone(buzzer, 475, 150, 80);
  tone(buzzer, 400, 600, 100);
}

void ohhh() {
  for (int i=1000; i<2000; i=i*1.02) { beep(buzzer,i,10); } for (int i=2000; i>1000; i=i*.98) {
  beep(buzzer,i,10);
  }
}

void uhoh() {
  for (int i=1000; i<1244; i=i*1.01) { beep(buzzer,i,30); } delay(200); for (int i=1244; i>1108; i=i*.99) {
  beep(buzzer,i,30);
 }
}

void cricketChirp(){
  for(int i=0; i<4; i++){
    tone(buzzer, 4000, 20, 15);
  }
  delay(450);
}

void loop() {
  
}
