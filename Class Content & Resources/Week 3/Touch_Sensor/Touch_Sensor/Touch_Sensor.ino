int key1 = 4;
int key2 = 3;
int key3 = 2;
int ledRed = 10;
int ledGreen = 9;
int ledBlue = 8;

void setup() {
  Serial.begin(9600);
  pinMode(key1, INPUT);
  pinMode(key2, INPUT);
  pinMode(key3, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);


}

void loop() {
  int keyValue1 = digitalRead(key1);
  int keyValue2 = digitalRead(key2);
  int keyValue3 = digitalRead(key3);
  Serial.println(keyValue1);

  if(keyValue1 == 0){
    digitalWrite(ledRed, HIGH);
  }else{
    digitalWrite(ledRed, LOW);
  }
  if(keyValue2 == 0){
    digitalWrite(ledGreen, HIGH);
  }else{
    digitalWrite(ledGreen, LOW);
  }
  if(keyValue3 == 0){
    digitalWrite(ledBlue, HIGH);
  }else{
    digitalWrite(ledBlue, LOW);
  }

}
