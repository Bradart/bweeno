/******************************************************************************************************************************************************** 
   This initial sketch will probably not be very well coded, if I'm being honest. I'm currently wrangling a four-year-old and 
   watching a particularly interesting episode of Ladybug and Cat Noire. This is just a rough sketch so that I don't feel like I
   wasted this entire day not doing anything remotely productive. Eat broccoli.


   Also, this was coded specifically for use on a Mega 2560 board but, with only 3 PWM pins in use, an uno should do just fine 
   IF YOU'RE A POOR PERSON GOD YOU DISGUST ME
   
   
   ADDENDUM: Yeah, it's for the Mega 2560. That board, however, is not mega enough to power the LEDs so here's more about what's happening here ---

    3 N-Channel MOSFETs (IRLB8721PBF, TO-220 package) with the gate pins hooked up to the bweeno. bweeno=arduino. Get over it.
    1 12V2A power supply, positive to the LED strip positive rail, negative common with the bweeno ground. Don't let that shit float, son.
    Standard 12V, 4-conductor LED strip. I thoroughly enjoy how simple the logic of these is and you can power a fuckload of them
    with this setup. 

  DOUBLE ADDENDUM: I now run this code on a Nano and it's dope. 
********************************************************************************************************************************************************/

#define redPot  A1   //The pin for the potentiometer controlling the red level
#define greenPot  A2 //Same for green
#define bluePot  A0 //and for blue

#define fetRed  3   //pin for the digital PWM output pin for red
#define fetGreen  5 //same for green
#define fetBlue  6  //same for blue

void setup() {
  //pinmodes. hooray.
  pinMode(redPot, INPUT);
  pinMode(greenPot, INPUT);
  pinMode(bluePot, INPUT);

  pinMode(fetRed, OUTPUT);
  pinMode(fetGreen, OUTPUT);
  pinMode(fetBlue, OUTPUT);
  //Serial.begin(9600);
}

void rainbow(){
  int red = 0;
  int blue = 0;
  int green = 255;
  for(int i = 0; i < 255; i++){
    analogWrite(fetRed, red);
    analogWrite(fetGreen, green);
    red++;
    green--;
    delay(5);
  }
  for (int i = 0; i < 255; i++){
    analogWrite(fetRed, red);
    analogWrite(fetBlue, blue);
    red--;
    blue++;
    delay(5);
  }
  for(int i = 0; i < 255; i++){
    analogWrite(fetBlue, blue);
    analogWrite(fetGreen, green);
    blue--;
    green++;
    delay(5);
  }
  
}
void loop() {
  //gotta get those analogue levels to turn them into delicious, free-range PWM
  int redLevAn = analogRead(redPot);
  int greenLevAn = analogRead(greenPot);
  int blueLevAn = analogRead(bluePot);

  //annnnnnnnnd let's convert them to PWM. ez pz
  int redLev = map(redLevAn, 0, 1023, 255, 0);
  int greenLev = map(greenLevAn, 0, 1023, 255, 0);
  int blueLev = map(blueLevAn, 0, 1023, 255, 0);

  if(redLev < 5){
    redLev = 0;
  }
  if(greenLev < 5){
    greenLev = 0;
  }
  if(blueLev < 5){
    blueLev = 0;
  }
  if(redLev > 254 && blueLev > 254 && greenLev > 254){
    rainbow();
  }
  else{
    //now we make that shit blast raw power directly to the LEDs because FUCK IT
    analogWrite(fetRed, redLev);
    analogWrite(fetGreen, greenLev);
    analogWrite(fetBlue, blueLev);  
  }


  delay(50);
  
 /* Serial.print("red:");
  Serial.print(redLev);
  Serial.print('\n');
  Serial.print("green:");
  Serial.print(greenLev);
  Serial.print('\n');
  Serial.print("blue:");
  Serial.print(blueLev);
  Serial.print('\n');
  Serial.print('\n');*/
}
