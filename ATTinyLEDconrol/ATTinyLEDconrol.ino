#include<FastLED.h>
const int NUM_LEDS = 30;
const int ledPin = 0;
const int potPin = 3;

CRGB led[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, ledPin, GRB>(led, NUM_LEDS);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  
}

void fadeall() { 
  for(int i = 0; i < NUM_LEDS; i++) { 
    led[i].nscale8(180); 
  }
}


void loop() {
  for(int i=0; i <= NUM_LEDS; i++){
    byte hue = map(analogRead(potPin), 0, 1023, 0, 255);
    led[i] = CHSV(hue, 255, 255);
    fadeall();
    FastLED.show();
    delay(20);
   }
  for(int i=NUM_LEDS; i > 0; i--){
    byte hue = map(analogRead(potPin), 0, 1023, 0, 255);
    led[i] = CHSV(hue, 255, 255);
    fadeall();
    FastLED.show();
    delay(20);
   }
}
