#include<FastLED.h>
const int NUM_LEDS = 10;
const int ledPin = 5;
const int potPin = 0;

CRGB led[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, ledPin, GRB>(led, NUM_LEDS);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}


void fadeall() { 
  for(int i = 0; i < NUM_LEDS; i++) { 
    led[i].nscale8(250); 
  }
}


void loop() {
  int hue = map(analogRead(potPin), 0, 1023, 0, 255);
  /*for(int i = 0; i < 5; i++){
    led[i] = 0x00FF7F;
  }
  for(int i = 5; i < NUM_LEDS; i++){
    led[i] = 0xFFA1FF;
  }*/
  for(int i = 0; i < 5; i++){
    led[i] = CHSV(224, 255, 150);
  }
  for(int i = 5; i < NUM_LEDS; i++){
    led[i] = CHSV(130, 255, 150);
  }
  FastLED.show();
  Serial.println(hue);
}
