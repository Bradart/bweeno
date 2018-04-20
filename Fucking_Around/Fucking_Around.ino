#include<FastLED.h>
const int NUM_LEDS = 90;
const int ledPin = 5;
const int potPin = 0;
const int lightPin = A1;

float hueSub = 0.02;
float hueMax = 255;
float hueMin = 0;
float hue = hueMin;

int lightThresh = 800;
int brightSub = 5;

CRGB led[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, ledPin, GRB>(led, NUM_LEDS);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);

          
//          Serial.begin(115200);
  
}

  void fadeall() { 
    for(int i = 0; i < NUM_LEDS; i++) { 
      led[i].nscale8(200); 
    }
  }

void hueChange() {
  hue = hue + hueSub;
  if(hue >= hueMax || hue <= hueMin){
    hueSub = -hueSub;
  }
}

void loop() {
//FastLED.clear();
int i = map(analogRead(lightPin), 10, lightThresh, 0, NUM_LEDS);

/*for(int j = 0; j <= i; j++){
  hue = map(analogRead(lightPin), 5, 105, 0, 255);
  led[j] = CHSV(hue, 255, 150);
  }

FastLED.show();
//fadeall();
//delay(20);
//FastLED.clear();
Serial.print("Light Level: ");
Serial.print(analogRead(lightPin));
Serial.print("\n");
Serial.print("LED no: ");
Serial.print(i);
Serial.print("\n");
Serial.print("\n");
*/



//static uint8_t brightness = 255;
  for(int i = 0; i < NUM_LEDS; i++){
    
//            Serial.println(analogRead(A1));

            
    int speed = map(analogRead(lightPin), 5, lightThresh, 3, 1);
    
    led[i] = CHSV(hue, 255, 150);
    
    hueChange();
    
    
    FastLED.show();
    //fadeall();
    
    //delay(speed);
    
  }

  for(int i = NUM_LEDS; i > 0; i = i - 1){
    
//            Serial.println(analogRead(test));
            
    int speed = map(analogRead(lightPin), 5, lightThresh, 3, 1);
    //hue = map(analogRead(lightPin), 5, lightThresh, 0, 255);
    
    led[i] = CHSV(hue, 255, 150);
    
    hueChange();
    
    
        
    FastLED.show();
    //fadeall();
    //delay(speed);
  }
  
  
}
