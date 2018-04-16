const int buzzPin = 8;
const int ledPin = 7;
const int buttonPin = 2;
const int cellPin = 0;
int buttonState = 0;
int buzzTone = 255;
int buzzSub = 10;
int cellState = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT_PULLUP);
pinMode(buzzPin, OUTPUT);
pinMode(cellPin, INPUT);
Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
 buttonState = digitalRead(buttonPin);
 cellState = analogRead(cellPin);
 Serial.println(cellState, DEC);
analogWrite(ledPin, buzzTone);
  delay(50);
  buzzTone = buzzTone - buzzSub;
  if(buzzTone <= 10 || buzzTone >= 255){
    buzzSub = -buzzSub;
if(buttonState == LOW){
  digitalWrite(buzzPin, HIGH);
  
}
  
  }
  else if(cellState >= 400){
  digitalWrite(buzzPin, HIGH);
  analogWrite(ledPin, buzzTone);
  delay(50);
  buzzTone = buzzTone - buzzSub;
  if(buzzTone <= 10 || buzzTone >= 255){
    buzzSub = -buzzSub;
  }
}
else{
  analogWrite(buzzPin, 0);
  analogWrite(ledPin, LOW);
}

}
