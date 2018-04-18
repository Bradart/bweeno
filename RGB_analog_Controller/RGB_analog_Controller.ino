/* This initial sketch will probably not be very well coded, if I'm being honest. I'm currently wrangling a four-year-old and 
   watching a particularly interesting episode of Ladybug and Cat Noire. This is just a rough sketch so that I don't feel like I
   wasted this entire day not doing anything remotely productive. Eat broccoli.


   Also, this was coded specifically for use on a Mega 2560 board but, with only 3 PWM pins in use, an uno should do just fine 
   IF YOU'RE A POOR PERSON GOD YOU DISGUST ME
   
   
   ADDENDUM: Yeah, it's for the Mega 2560. That board, however, is not mega enough to power the LEDs so here's more about what's happening here ---

    3 N-Channel MOSFETs (IRLB8721PBF, TO-220 package) with the gate pins hooked up to the bweeno. bweeno=arduino. Get over it.
    1 12V2A power supply, positive to the LED strip positive rail, negative common with the bweeno ground. Don't let that shit float, son.
    Standard 12V, 4-conductor LED strip. I thoroughly enjoy how simple the logic of these is and you can power a fuckload of them
      with this setup. 
  */

const int redPot = A0;   //The pin for the potentiometer controlling the red level
const int greenPot = A1; //Same for green
const int bluePot = A2; //and for blue

const int fetRed = 2;   //pin for the digital PWM output pin for red
const int fetGreen = 3; //same for green
const int fetBlue = 4;  //same for blue

//I'm adding indicators because what are you my dad step off old man I'm busy
const int redInd = 5;
const int greenInd = 6;
const int blueInd = 7;



void setup() {
  //pinmodes. hooray.
  pinMode(redPot, INPUT);
  pinMode(greenPot, INPUT);
  pinMode(bluePot, INPUT);

  pinMode(fetRed, OUTPUT);
  pinMode(fetGreen, OUTPUT);
  pinMode(fetBlue, OUTPUT);

  pinMode(redInd, OUTPUT);
  pinMode(greenInd, OUTPUT);
  pinMode(blueInd, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  //gotta get those analogue levels to turn them into delicious, free-range PWM
  int redLevAn = analogRead(redPot);
  int greenLevAn = analogRead(greenPot);
  int blueLevAn = analogRead(bluePot);

  //annnnnnnnnd let's convert them to PWM. ez pz
  int redLev = redLevAn / 4;
  int greenLev = greenLevAn /4;
  int blueLev = blueLevAn / 4;

  //compensating for the fact that 255 doesn't divide evenly into 1024
  if(redLev < 5){
    redLev = 0;  
  }

  if(greenLev < 5){
    greenLev = 0;
  }

  if(blueLev < 5){
    blueLev = 0;
  }

  //now we make that shit blast raw power directly to the LEDs because FUCK IT
  analogWrite(fetRed, redLev);
  analogWrite(fetGreen, greenLev);
  analogWrite(fetBlue, blueLev);  

  //the indicators operating on the same pwm as the controller mosfets
  analogWrite(redInd, redLev);
  analogWrite(greenInd, greenLev);
  analogWrite(blueInd, blueLev);  

  delay(50);
  
  Serial.print("red:");
  Serial.print(redLev);
  Serial.print('\n');
  Serial.print("green:");
  Serial.print(greenLev);
  Serial.print('\n');
  Serial.print("blue:");
  Serial.print(blueLev);
  Serial.print('\n');
  Serial.print('\n');
}
