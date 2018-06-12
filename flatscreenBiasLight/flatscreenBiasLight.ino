#include<FastLED.h>
#define NUM_LEDS 37
#define ledPin 0
#define powPin 1
#define huePot A1
#define satPot A3
#define brightPot A2

byte butStat = HIGH;
int satSet;
byte hue = 0;
byte lastHue = 0;
bool powStat = false;
bool rainStat = false;

long lastDeb = 0;
long debDelay = 150;

void rainbow();
void lightsOn();
void lightsOff();

CRGB led[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812B, ledPin, GRB>(led, NUM_LEDS);
  pinMode(ledPin, OUTPUT);
  pinMode(powPin, INPUT_PULLUP);

}

void loop() {
  butStat = digitalRead(powPin);
  satSet = analogRead(satPot);
  if(satSet <= 5){
    rainStat = true;
  }
  
  else{
    rainStat = false;
  }
  
  if((millis() - lastDeb) > debDelay){
    if(butStat == LOW){
      powStat = !powStat;
      lastDeb = millis();
    }
  }
  
  if(powStat && !rainStat){
    lightsOn();
  }
  else if(powStat && rainStat){
    rainbow(&powStat);
  }

  
  if(!powStat && !rainStat){
    lightsOff();
  }
}

void rainbow(bool *pows) { //a slow-progressing rainbow
  hue = lastHue;
  for (int i = 0; i < NUM_LEDS; i++) {
    led[i] = CHSV(hue, 255, 255);
    hue+=3;
    if ((millis() - lastDeb) > debDelay) {
      if (digitalRead(powPin) == LOW) {
        *pows = false;
        break;
      }
    }
    
    //delay(50);
  }
  FastLED.show();
  FastLED.delay(30);

  lastHue+=3;
  //delay(500);
  *pows = true;
  return;
}

void lightsOn() {
  for (int i = 0; i < NUM_LEDS; i++) {
    int bright_ = analogRead(brightPot)/4;
    int hue_ = analogRead(huePot)/4;
    int sat_ = analogRead(satPot)/4;
    led[i] = CHSV(hue_, sat_ , bright_);
    if((millis() - lastDeb) > debDelay){
      if(digitalRead(powPin) == LOW){
        powStat = false;
        lastDeb = millis();
        return;              
      }
    }
  }
  FastLED.show();
}

void lightsOff() {
  for (int i = 0; i < NUM_LEDS; i++) {
    led[i] = CHSV(0, 0, 0);
  }
  FastLED.show();
  
}

