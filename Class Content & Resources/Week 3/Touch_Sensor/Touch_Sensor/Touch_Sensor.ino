
int pulsePin1 = 7;
int pulsePin2 = 6;
int pulsePin3 = 5;
int touch1 = 4;
int touch2 = 3;
int touch3 = 2;
int ledRed = 12;
int ledGreen = 11;
int ledBlue = 10;

void setup() {
  Serial.begin(9600);
  pinMode(pulsePin1, OUTPUT);
  pinMode(pulsePin2, OUTPUT);
  pinMode(pulsePin3, OUTPUT);
  pinMode(touch1, INPUT);
  pinMode(touch2, INPUT);
  pinMode(touch3, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);


}

void loop() {

  capSense(pulsePin1, touch1, ledRed, "RED");
  capSense(pulsePin2, touch2, ledGreen, "GREEN");
  capSense(pulsePin3, touch3, ledBlue, "BLUE");
//  Serial.println();

}

void capSense(int triggerPin, int touchPin, int ledPin, String LED) {
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(triggerPin, LOW);

  int duration = pulseIn(touchPin, HIGH, 1000);

//  Serial.print(LED);
//  Serial.print("\t");
//  Serial.print(duration);
//  Serial.print("\t");

  if (duration > 0) {
    digitalWrite(ledPin, HIGH);
    delay(100);
  } else {
    digitalWrite(ledPin, LOW);
  }

}
