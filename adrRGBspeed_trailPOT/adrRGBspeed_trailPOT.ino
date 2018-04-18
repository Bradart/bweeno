#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 90

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 5
#define CLOCK_PIN 13

#define POT A0
int sub = 3;
// Define the array of leds
CRGB leds[NUM_LEDS];

int light = 0;

void setup() { 
  //Serial.begin(115200);
      // Uncomment/edit one of the following lines for your leds arrangement.
      // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
       FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  	  // FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      // FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
      
      // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<P9813, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<APA102, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<DOTSTAR, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      
}
void fadeall() { 
  int dial = analogRead(POT);
  int tail = map(dial, 0, 1023, 220, 250);
  for(int i = 0; i < NUM_LEDS; i++) { 
leds[i].nscale8(tail); 

} }
void loop() { 
  // Turn the LED on, then pause
int dial = analogRead(POT);

int tail = map(dial, 0, 1023, 0, 255);

static uint8_t hue = 70;

//FastLED.clear();
  for(int i = 0; i < NUM_LEDS; i++){
  //FastLED.clear();
  //leds[i] = CHSV(hue = hue + 5, 255, 255);
  //leds[i-1] = CRGB::Blue;
  //leds[i] = CRGB::Blue;
  //leds[i+1] = CRGB::Blue;

  leds[i] = CHSV(hue, 255, 255);
  FastLED.show();
  //leds[i] = CRGB::Black;
  //delay(10);
  //FastLED.show();
  delay(light);
  fadeall();
  dial = analogRead(POT);
  light = map(dial, 0, 1023, 10, 200);


  

  hue = hue + sub;

  if(hue >= 255){
    sub = -sub;
  }
  else if(hue <= 0){
    sub = -sub;
  }
  
  }

  for(int i = NUM_LEDS - 1; i >= 0; i--){
  //FastLED.clear();
  leds[i] = CHSV(hue, 255, 255);
  //leds[i-1] = CRGB::Blue;
  //leds[i] = CRGB::Green;
  //leds[i+1] = CRGB::Blue;

 
  FastLED.show();
  //leds[i] = CRGB::Black;
  delay(light);
  //FastLED.show();
  fadeall();
  dial = analogRead(POT);
  light = map(dial, 0, 1023, 10, 200);
  //leds[i] = CHSV(hue++, 255, 255);

  hue = hue + sub;

  if(hue >= 255){
    sub = -sub;
  }
  else if(hue <= 0){
    sub = -sub;
  }

  }


}
