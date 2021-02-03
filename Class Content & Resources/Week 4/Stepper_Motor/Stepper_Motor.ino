#include <Stepper.h>

// change this to the number of steps on your motor
int stepsPerRevolution = 32;
int motorSpeed = 100;
int motorStep = 64;

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int pot = A0;

void setup() {
  Serial.begin(9600);
  pinMode(pot, INPUT);
  myStepper.setSpeed(motorSpeed);
}

void loop() {
  // get the sensor value
  int potReading = analogRead(pot);
  motorSpeed = abs(map(potReading, 0, 1023, -600, 600)) + 100;
  myStepper.setSpeed(motorSpeed);
  if (potReading >= 512) {
    myStepper.step(motorStep);
    
  } else {
    myStepper.step(-motorStep);
 
  }
  delay(10);

  Serial.println(motorSpeed);



}
