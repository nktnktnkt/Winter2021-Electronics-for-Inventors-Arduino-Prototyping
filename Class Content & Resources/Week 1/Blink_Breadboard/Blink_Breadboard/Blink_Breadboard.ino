//initialize the global variables
int led = 13;
int led2 = 12;
int ledRed = 7;
int ledGreen = 6;
int ledBlue = 5;
int modulo = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  modulo = modulo + 1;
  int delayValue = 5 * modulo;
  if(delayValue > 100) {
    modulo = 0;
  }
  
  digitalWrite(led, HIGH);
  digitalWrite(led2, HIGH);
  delay(delayValue);
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  delay(delayValue);
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayValue);               // wait for a second
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(delayValue);  // wait for a second

  digitalWrite(ledRed, HIGH);
  delay(delayValue);
  digitalWrite(ledRed, LOW);
  delay(delayValue);
  digitalWrite(ledGreen, HIGH);
  delay(delayValue);
  digitalWrite(ledGreen, LOW);
  delay(delayValue);
  digitalWrite(ledBlue, HIGH);
  delay(delayValue);
  digitalWrite(ledBlue, LOW);
  delay(delayValue);

  //purple
  digitalWrite(ledBlue, HIGH);
  digitalWrite(ledRed, HIGH);
  delay(delayValue);
  digitalWrite(ledBlue,LOW);
  digitalWrite(ledRed, LOW);
  delay(delayValue);

  //yellow
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledRed, HIGH);
  delay(delayValue);
  digitalWrite(ledGreen,LOW);
  digitalWrite(ledRed, LOW);
  delay(delayValue);

  //teal
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, HIGH);
  delay(delayValue);
  digitalWrite(ledGreen,LOW);
  digitalWrite(ledBlue, LOW);
  delay(delayValue);
}
