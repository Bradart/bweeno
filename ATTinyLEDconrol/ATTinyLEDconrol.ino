/*********************************************************************************************************************************
   The controller for a neato-burrito light that is on my bedroom window. A strip of 30 LEDs diffused by my venetian(sp?) blinds.
   It looks fucking dope and you're an idiot if you don't love it.
   I'm now going back through and I'm going to try and comment this as thoroughly as possible as an exercide in not being a shit
   coder.
 *********************************************************************************************************************************/

#include<FastLED.h>
const int NUM_LEDS = 30; //the number of LEDs on your light strip
const int ledPin = 0; //The pin those LEDs are on
const int butPin = 1; //The pin that will activate the cylon behavior
const int onPin = 2; //The pin that will activate the standard "lamp" behavior
const int potPin = A3; //The pin to which you will connect the potentiometer for color control
const int brightPin = A2; //The pin for the potentiometer that is to control the brightness of the light.

byte hue_ = 0;
byte lastHue = 0;
int but; //button 1 state variable (cylon) [I need to make this variable name not shitty]
int but2; //button 2 state variable (lamp) ^^
bool power = false; //boolean varibale controling cyclon behavior
bool allOn = false; //same for lamp behavior
bool rainy = false;

long lastDeb = 0;
long debDelay = 150;

CRGB led[NUM_LEDS]; //declaring the FastLED strip

//declaring the functions, details of which will be described down in the "here's what the functions are to do" area
void cylOn();
void lightOn();
void lightoff();
void rainbow();
void fadeall();

//The Setup
void setup() {
  FastLED.addLeds<WS2812B, ledPin, GRB>(led, NUM_LEDS); //Making FastLED do the thing
  pinMode(butPin, INPUT_PULLUP); //Self explanatory. PULLUP, so reverse logic
  pinMode(ledPin, OUTPUT); //^^
  pinMode(potPin, INPUT); //^^
  pinMode(onPin, INPUT_PULLUP); //^^

}

//The main loop
void loop() {
  but = digitalRead(butPin); //polling button
  but2 = digitalRead(onPin); //polling the other button
  int rainTime = analogRead(potPin);
  if (rainTime > 1000) {
    rainy = true;
  }
  else{
    rainy = false;
  }
  if ((millis() - lastDeb) > debDelay) {
    if (but == LOW) { //on button press (remember----reverse logic)
      power = !power; //flip the power variable to kick the function to the below power setting
      lastDeb = millis();
    }
    if (but2 == LOW) { //same but for button press of button 2
      allOn = !allOn; //ditto again but for the all-on setting
      lastDeb = millis();
    }
  }
  if (allOn && !power && !rainy) {
    lightOn(&allOn); //start cycling through the allOn function passing a pointer to the allOn variable so the function can change the state
  }
  else if (power && !allOn && !rainy) {
    cylOn(&power, &allOn); //Start cycling through the cylon function with the same pointer situation as allOn
  }
  else if (allOn && rainy && !power) {
    rainbow(&allOn, &rainy);
  }
  else if (!power && !allOn) { //The default off state when neither Cylon nor All-on functions are set
    lightOff(&power, &allOn); //run the lights off function to turn...the...lights...off?
  }

}

//The cylon function. Makes a beam of light bounce from end to end on the light strip.
void cylOn(bool *pP, bool *all_) {
  //make the beam of light do the thing
  for (int i = 0; i <= NUM_LEDS; i++) {
    byte hue = analogRead(potPin)/4; //read
    byte bright = analogRead(brightPin)/4;
    led[i] = CHSV(hue, 255, bright);
    fadeall();
    FastLED.show();
    FastLED.delay(20);
    if ((millis() - lastDeb) > debDelay) {
      if (!digitalRead(butPin)) { //keep polling to see if the process was cancelled
        *pP = false;
        *all_ = false;
        lastDeb = millis();
        return;
      }
    }
  }
  //make the whatever do the thing in the opposite direction
  for (int i = NUM_LEDS; i > 0; i--) {
    byte hue = analogRead(potPin)/4;
    byte bright = analogRead(brightPin)/4;
    led[i] = CHSV(hue, 255, bright);
    fadeall();
    FastLED.show();
    FastLED.delay(20);
    if ((millis() - lastDeb) > debDelay) {
      if (!digitalRead(butPin)) { //keep polling to see if the process was cancelled
        *pP = false;
        *all_ = false;
        lastDeb = millis();
        return;
      }
    }
  }
  *pP = true;
  *all_ = false;

}

//killing the lights. Super self-explanatory here
void lightOff(bool *offP, bool *allOffP) {
  for (int i = 0; i < NUM_LEDS; i++) {
    led[i] = CHSV(0, 0, 0);
  }
  FastLED.show();
  *offP = false; //flip them states
  *allOffP = false; //^^
}

//LET THERE BE LIIIIIIIIIIIIGHT!
void lightOn(bool *allOnP) {
  for (int i = 0; i < NUM_LEDS; i++) {
    byte hue = analogRead(potPin)/4; //Read them color and brightness states
    byte bright = analogRead(brightPin)/4;
    if ((millis() - lastDeb) > debDelay) {
      if (!digitalRead(onPin)) { //button polling
        *allOnP = false;
        lastDeb = millis();
        return;
      }
    }
    led[i] = CHSV(hue, 255, bright);
  }
  FastLED.show();
  *allOnP = true;
}

void fadeall() { //the scaling function for the led fades.
  for (int i = 0; i < NUM_LEDS; i++) {
    led[i].nscale8(200);
  }
}

void rainbow(bool *pows, bool *rains) { //a slow-progressing rainbow
  hue_ = lastHue;
  for (int i = 0; i < NUM_LEDS; i++) {
    int bright_ = analogRead(brightPin)/4;
    led[i] = CHSV(hue_, 255, bright_);
    hue_ += 3;
    if ((millis() - lastDeb) > debDelay) {
      if (digitalRead(onPin) == LOW) {
        *pows = false;
        *rains = false;
        lastDeb = millis();
        break;
      }
    }

    //delay(50);
  }
  lastHue += 3;
  FastLED.show();
  FastLED.delay(30);
  *pows = true;
  *rains = true;
}
