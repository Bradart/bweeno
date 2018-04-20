#include<FastLED.h>
const int NUM_LEDS = 90;
const int ledPin = 5;
const int potPin = 0;

CRGB led[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, ledPin, GRB>(led, NUM_LEDS);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  
}

void fadeall() { 
  for(int i = 0; i < NUM_LEDS; i++) { 
    led[i].nscale8(250); 
  }
}


void loop() {
  
}
