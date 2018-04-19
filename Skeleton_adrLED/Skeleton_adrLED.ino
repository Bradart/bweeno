#include<FastLED.h>
const int NUM_LEDS = 90;
const int ledPin = 5;
const int potPin = 0;
int brightSub = 5;
CRGB led[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, ledPin, GRB>(led, NUM_LEDS);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  //Serial.begin(115200);
  
}

  void fadeall() { 
    for(int i = 0; i < NUM_LEDS; i++) { 
      led[i].nscale8(200); 
    }
  }


void loop() {
static uint8_t hue = 0;
//static uint8_t brightness = 255;
  for(int i = 0; i < NUM_LEDS; i = i + 2){
    int speed = map(analogRead(potPin), 0, 700, 100, 1);
    led[i] = CHSV(hue, 255, 150);
    hue++;
    /*brightness = brightness - brightSub;
    if(brightness < 20 || brightness >= 255){
      brightSub = -brightSub;
    }*/
    FastLED.show();
    fadeall();
    delay(pow(speed, 2));
    //Serial.println(analogRead(potPin));
  }

  for(int i = NUM_LEDS; i > 0; i = i - 1){
    int speed = map(analogRead(potPin), 0, 700, 100, 1);
    led[i] = CHSV(hue, 255, 150);
    hue++;
    /*brightness = brightness - brightSub;
    if(brightness < 20 || brightness >= 255){
      brightSub = -brightSub;
    }*/
    FastLED.show();
    fadeall();
    delay(speed);
  }
  
}
