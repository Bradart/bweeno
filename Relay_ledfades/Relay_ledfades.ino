/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 3;     // the number of the pushbutton pin
const int relPin =  2;      // the number of the LED pin
const int potPin = 0;
const int ledAna = 5;
const int ledGo = 9;
int bright = 0;
//int bbright = 0;
int fadeAm = 3;
//int fadeAmm = 3;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int potState = 0;
void setup() {
  // initialize the LED pin as an output:
  pinMode(relPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  //initializing analog pin for potentiometer
  pinMode(potPin, INPUT);
  pinMode(ledGo, OUTPUT);
  pinMode(ledAna, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  potState = analogRead(potPin);
  

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    
    bright = bright + fadeAm;
    if(bright <= 0 || bright >=255){
      fadeAm = -fadeAm;
    }

      /*bbright = bbright + fadeAmm;
    if(bbright <= 0 || bbright >=160){
      fadeAmm = -fadeAmm;
    }
*/
    
    delay(20);
    
    if (potState > 800){
    analogWrite(ledAna, potState / 4);
    digitalWrite(relPin, LOW);
    analogWrite(ledGo, bright);

     
      if (potState > 1000){

        digitalWrite(ledGo, LOW);
        
        delay(500);
        
        digitalWrite(ledGo, HIGH);
        digitalWrite(relPin, HIGH);
        
        delay(500);
      }
    }
    else if (potState < 800){
      digitalWrite(relPin, HIGH);
      //digitalWrite(ledGo, LOW);
      analogWrite(ledAna, bright);
      analogWrite(ledGo, -bright);
      
    }
    
  }
  else {
    digitalWrite(relPin, HIGH);
    analogWrite(ledAna, 0);
    
    }
  
  Serial.println(fadeAm);
}
