int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int potPin = A0;

int buttonRed = 4;
int buttonGreen = 3;
int buttonBlue = 2;

int colorSelect = 11;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(potPin, INPUT);

  pinMode(buttonRed, INPUT);
  pinMode(buttonGreen, INPUT);
  pinMode(buttonBlue, INPUT);
}

void loop() {
  int potReading = analogRead(potPin);
  //Serial.println(potReading);

  int potScaled = map(potReading, 0, 1023, 0, 255);
  //Serial.println(potScaled);

  int buttonRedReading = digitalRead(buttonRed);
  int buttonGreenReading = digitalRead(buttonGreen);
  int buttonBlueReading = digitalRead(buttonBlue);

  if (buttonRedReading == HIGH) {
    colorSelect = redPin;

  }
  if (buttonGreenReading == HIGH) {
    colorSelect = greenPin;

  }
  if (buttonBlueReading == HIGH) {
    colorSelect = bluePin;

  }
  Serial.println(buttonGreenReading);

  analogWrite(colorSelect, potScaled);

}
