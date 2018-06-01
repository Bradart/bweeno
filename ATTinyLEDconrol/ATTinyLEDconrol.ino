#include<FastLED.h>
const int NUM_LEDS = 30;
const int ledPin = 0;
const int butPin = 1;
const int onPin = 2;
const int potPin = A3;
const int brightPin = A2;
int but;
int but2;
bool power = false;
bool allOn = false;
CRGB led[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, ledPin, GRB>(led, NUM_LEDS);
  pinMode(butPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(onPin, INPUT_PULLUP);
  
}

void cylOn(bool *pP) {
  for(int i = 0; i <= NUM_LEDS; i++){
    byte hue = map(analogRead(potPin), 0, 1023, 0, 255);
    byte bright = map(analogRead(brightPin), 0, 1025, 0, 255);
    led[i] = CHSV(hue, 255, bright);
    fadeall();
    FastLED.show();
    delay(20);
    if(!digitalRead(butPin)){
      *pP = false;
      delay(300);
      return; 
    }
    }
  for(int i=NUM_LEDS; i > 0; i--){
    byte hue = map(analogRead(potPin), 0, 1023, 0, 255);
    byte bright = map(analogRead(brightPin), 0, 1025, 0, 255);
    led[i] = CHSV(hue, 255, bright);
    fadeall();
    FastLED.show();
    delay(20);
    if(!digitalRead(butPin)){
      *pP = false;
      delay(300);
      return;
    }
   }
   *pP = true;

}

void lightOff(bool *offP, bool *allOffP){
  for(int i = 0; i < NUM_LEDS; i++){
    led[i] = CHSV(0, 0, 0);
  }
  FastLED.show();
  *offP = false;
  *allOffP = false;
}

void lightOn(bool *allOnP){
  for(int i = 0; i < NUM_LEDS; i++){
    byte hue = map(analogRead(potPin), 0, 1023, 0, 255);
    byte bright = map(analogRead(brightPin), 0, 1025, 0, 255);
    if(!digitalRead(onPin)){
      *allOnP = false;
      delay(300);
      return;
    }
    led[i] = CHSV(hue, 255, bright);
  }
  FastLED.show();
  *allOnP = true;
}

void fadeall() { 
  for(int i = 0; i < NUM_LEDS; i++) { 
    led[i].nscale8(200); 
  }
}


void loop() {
  while(!power && !allOn){
  lightOff(&power, &allOn);
    but = digitalRead(butPin);
    but2 = digitalRead(onPin);
    if(!but){
      delay(300);
      power = !power;
      break;
    }
    else if(!but2){
      delay(300);
      allOn = !allOn; 
      break;
    }
  }
  while(allOn && !power){
    lightOn(&allOn);
    break;
    }
  while(power){
    cylOn(&power);
    break;
    }
  }

