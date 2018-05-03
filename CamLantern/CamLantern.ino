#include<FastLED.h>
const int NUM_LEDS = 8; //the number of LEDs in the array
const int ledPin = 12; //the pin the LED data line connects to
const int huePot = A7; //the potentiometer that control the color of the lights
const int brightPot = A6; //the potentiometer that controls the brightness
const int powerSwitch = 4; //the pin for the power button 

int hue = 0;
int bright = 0; //the hue and brightness values we'll manipulate later
float bright2 = 250;
float breathe = .2;
CRGB led[NUM_LEDS]; //initialising the LED array

void setup() {
  FastLED.addLeds<WS2812B, ledPin, GRB>(led, NUM_LEDS);//setting up the LED parameters
  pinMode(ledPin, OUTPUT); //self explanatory
  pinMode(brightPot, INPUT); // ^^
  pinMode(huePot, INPUT); // ^^
  pinMode(powerSwitch, INPUT_PULLUP); // ^^
  
}

void fadeall() { //a light fading function in case I ever choose to incorporate that later
  for(int i = 0; i < NUM_LEDS; i++) { 
    led[i].nscale8(180); 
  }
}


void loop() {
int  state = digitalRead(powerSwitch); //reads the power switch state so it knows if the light should be on or not
  if(state == LOW){ //if the power button is on

    bright = map(analogRead(brightPot), 0, 1023, 255, 0);
    
    if(bright > 250){
      
      for(int i = 0; i <= NUM_LEDS; i++){ //set the LED values
        bright = map(analogRead(brightPot), 0, 1023, 255, 0);
        hue = map(analogRead(huePot), 0, 1023, 255, 0);
        if(bright2 >= 255 || bright2 <= 75){
          breathe = -breathe;
        }
        bright2 += breathe;
        led[i] = CHSV(hue, 255, bright2);
      }
      
        
        FastLED.show();
        delay(20); 
        
      /*for(int i = NUM_LEDS; i >= 0; i--){ //set the LED values
        bright = map(analogRead(brightPot), 0, 1023, 255, 0);
        hue = map(analogRead(huePot), 0, 1023, 255, 0);
        led[i] = CHSV(hue, 255, 255);
        FastLED.show();
        fadeall();
        delay(40);
      }*/
      
    }

    else{
    
    for(int i = 0; i <= NUM_LEDS; i++){ //set the LED values
      bright = map(analogRead(brightPot), 0, 1023, 255, 0);
      hue = map(analogRead(huePot), 0, 1023, 255, 0);
      
      if(hue >= 250){ //a white light mode for added brightness
        led[i] = CHSV(255, 0, bright);
      }
      else{
        led[i] = CHSV(hue, 255, bright);
      }
    }
  }
  }
  else if(state == HIGH){ //if the power button is off
    for(int i = 0; i <= NUM_LEDS; i++){
      led[i] = CHSV(hue, 0, 0); //turn the LEDs off
    }
  }
    FastLED.show(); //keeping this outside of the for loops makes the transitions much smoother since all LEDs are intended to be the same color
  }

  

