
int pulsePin1 = 7;
int pulsePin2 = 6;
int pulsePin3 = 5;
int key1 = 4;
int key2 = 3;
int key3 = 2;
int ledRed = 12;
int ledGreen = 11;
int ledBlue = 10;

void setup() {
  Serial.begin(9600);
  pinMode(pulsePin1, OUTPUT);
  pinMode(pulsePin2, OUTPUT);
  pinMode(pulsePin3, OUTPUT);
  pinMode(key1, INPUT);
  pinMode(key2, INPUT);
  pinMode(key3, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);


}

void loop() {

  capSense(pulsePin1, key1, ledRed, "RED");
  capSense(pulsePin2, key2, ledGreen, "GREEN");
  capSense(pulsePin3, key3, ledBlue, "BLUE");
  Serial.println();

}

void capSense(int triggerPin, int keyPin, int ledPin, String LED) {

  int trigReading = digitalRead(triggerPin);
  if (trigReading == LOW) {
    digitalWrite(triggerPin, HIGH);
  } else {
    digitalWrite(triggerPin, LOW);
  }

  int duration = pulseIn(keyPin, HIGH, 100);
  Serial.print(LED);
  Serial.print("\t");
  Serial.print(duration);
  Serial.print("\t");

  if (duration > 0) {
    digitalWrite(ledPin, HIGH);
    delay(100);
  } else {
    digitalWrite(ledPin, LOW);
  }

}
