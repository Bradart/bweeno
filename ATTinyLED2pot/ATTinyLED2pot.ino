#include<FastLED.h>

#define ledPin 0
#define rainbowButton 1
#define brightPot A2
#define huePot A3
#define powerSwitch 2 
const int NUM_LEDS = 30;
bool rainState = 0;

CRGB led[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, ledPin, GRB>(led, NUM_LEDS);
  pinMode(ledPin, OUTPUT);
  pinMode(huePot, INPUT);
  pinMode(brightPot, INPUT);
  pinMode(rainbowButton, INPUT_PULLUP);
  pinMode(powerSwitch, INPUT_PULLUP);
  
}

void fadeall() { 
  for(int i = 0; i < NUM_LEDS; i++) { 
    led[i].nscale8(180); 
  }
}


void loop() {
  byte powerState = digitalRead(powerSwitch);
  byte hue = map(analogRead(huePot), 0, 1023, 5, 255); 
  byte bright = map(analogRead(brightPot), 0, 1023, 5, 255);
  /*if(digitalRead(rainbowButton) == LOW){
    if(rainState = 0){
      rainState = 1;
    }
    else if(rainState = 1){
      rainState = 0;
    }
  }
  */
  if(powerState == HIGH){
  /*if(digitalRead(rainbowButton) == LOW){
    if(rainState = 0){
      rainState = 1;
    }
    else if(rainState = 1){
      rainState = 0;
    }
    if(rainState == 1){
      int rHue = 0;
      for(byte i = 0; i <= NUM_LEDS; i++){
        bright = map(analogRead(brightPot), 0, 1023, 5, 255);
        led[i] = CHSV(rHue, 255, bright);
        FastLED.show();
        fadeall();
        rHue++;
        delay(15);
      }
      for(byte i = NUM_LEDS; i >= 0; i--){
        bright = map(analogRead(brightPot), 0, 1023, 5, 255);
        led[i] = CHSV(rHue, 255, bright);
        FastLED.show();
        fadeall();
        rHue++;
        delay(15);
      }
    }
  else{*/      
      for(byte i = 0; i <= NUM_LEDS; i++){
        led[i] = CHSV(0, 0, 0);
      }
      FastLED.show();
    }
  
  else if(powerState == LOW){
    for(byte i = 0; i <= NUM_LEDS; i++){
      bright = map(analogRead(brightPot), 0, 1023, 5, 255);
      led[i] = CHSV(hue, 255, bright);  
    }
    FastLED.show();
  }
}

