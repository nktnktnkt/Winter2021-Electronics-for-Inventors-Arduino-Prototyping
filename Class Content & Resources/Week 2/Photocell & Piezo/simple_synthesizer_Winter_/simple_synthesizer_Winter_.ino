int lightSensor = A0;
int tuner = A2;
int noteControl = A1;
int lightLow = 120; //set the lowest value the light sensor (photocell) outputs
int lightHigh = 500; // set the highest value the light sensor outputs.
int button = 2;
int buzzer = 11;

void setup() {
  Serial.begin(9600); 
  pinMode(buzzer, OUTPUT);
  pinMode(tuner, INPUT);
  pinMode(lightSensor, INPUT);
  pinMode(noteControl, INPUT);
  pinMode(button, INPUT);
}

void loop() {
  //read the tuner pot to set the master pitch of the piezo speaker
  int tunerValue = analogRead(tuner);
  int frequency = map(tunerValue, 0, 1023, 440, 3520);

  //read the light sensor value to control the harmonic tuning of the audio waveform relative to the master tuning, creating simple melodies.
  int lightValue = analogRead(lightSensor);
  Serial.println(lightValue); //use this reading to determine lightHigh and lightLow values
  int melody = map(lightValue, lightLow , lightHigh, 1, 10);
  melody = constrain(melody, 1, 10);

  //read the noteControl pot to modify the PWM state of the audio signal, creating a FM (frequency modulation) effect on the sound.
  int noteValue = analogRead(noteControl);
  unsigned long noteLength = map(noteValue, 0 , 1023, 100, 1000);

  //read the push button's state to turn on and off the piezo output. The piezo will only make noise when the button is pushed down.
  int buttonState = digitalRead(button);


  //Push the button to generate audio, with the "delayMicroseconds" controling the duty cycle length of the waveform, which changes the percieved pitch
  if (buttonState == HIGH) {
    
    tone(buzzer, frequency / melody, noteLength);
    
  }

}
