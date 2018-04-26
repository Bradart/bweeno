#include<FastLED.h>
const int NUM_LEDS = 90;
const int ledPin = 3;
const int huePot = A1;
const int brightPot = A2;
const int powerSwitch = 2;

int hue = 0;
int bright = 0;
CRGB led[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, ledPin, GRB>(led, NUM_LEDS);
  pinMode(ledPin, OUTPUT);
  pinMode(brightPot, INPUT);
  pinMode(huePot, INPUT);
  pinMode(powerSwitch, INPUT_PULLUP);
  
}

void fadeall() { 
  for(int i = 0; i < NUM_LEDS; i++) { 
    led[i].nscale8(250); 
  }
}


void loop() {
int  state = digitalRead(powerSwitch);
hue = map(analogRead(huePot), 0, 1023, 255, 0);
  if(state = LOW){
    for(int i = 0; i <= NUM_LEDS; i++){
      bright = map(analogRead(brightPot), 0, 1023, 255, 0);
      led[i] = CHSV(hue, 255, bright);
      FastLED.show();
      hue = map(analogRead(huePot), 0, 1023, 255, 0);
    }
    
    }
    else if(state == HIGH){
    FastLED.clear();
    }
  }
  

