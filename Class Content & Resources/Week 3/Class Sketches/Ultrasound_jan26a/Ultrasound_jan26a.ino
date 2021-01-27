int ledPin = 9;
int buzzerPin = 10;
int trigPin = 8;
int echoPin = 6;
float distanceMin = 1;
float distanceMax = 7;
int multiplier = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance = duration / 169;
  Serial.println(distance);
  int ledValue = map(distance * multiplier, distanceMin * multiplier, distanceMax * multiplier, 255, 0);
  int toneValue = map(distance * multiplier, distanceMin * multiplier, distanceMax * multiplier, 880, 220);
  
  if (distance >= distanceMin && distance <= distanceMax) {

    analogWrite(ledPin, ledValue);
    tone(buzzerPin, toneValue);
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

}
