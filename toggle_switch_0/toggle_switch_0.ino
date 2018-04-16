//This is for the Arduino Mega 2560. Maybe it will work on other Arduinos. Maybe not. Figure it out. I'm busy.
//initializing the pin numbers

//the annoying buzzer
const int buzzPin = 8;
//The LED
const int ledPin = 7;
//The pin for the tac switch
const int buttonPin = 2;
//The pin for the photocell that I'm pretty sure doesn't get used in this project. Cool.
const int cellPin = 0;



/*
 I'm adding this comment purely to try and commit it to the git without fucking anything up. LETS SEE IF I FUCK EVERYTHING UP OH GODDDDDDDD
 */




//initializing the variables that vary

//the state of the button, obvi
int buttonState = 0;
//a PWM value that used to refer to the tone of the buzzer but now control the LED brightness. Neat.
int buzzTone = 255;
//the value that is added and subtracted to facilitate the smooth LED fade that looks just so fucking dope
int buzzSub = 20;
//the initializing of the variable for that light sensor that isn't used in this project
int cellState = 0;
//The boolean variable that makes this whole shit work like a toggle switch
bool offOn = false;


void setup() {
//setting up the pin modes. That's why it says "pinMode". Welcome to the jungle.
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT_PULLUP);
pinMode(buzzPin, OUTPUT);
pinMode(cellPin, INPUT);

//beginning the serial output so I can see what I'm fucking up in REAL TIME
Serial.begin(9600);
}

void loop() {

//read that button state, son.
  buttonState = digitalRead(buttonPin);


//Here's where the code checks if the button is pressed
  if(buttonState == LOW){
    //a delay so that you have time to take your finger off the buzzer
    delay(200);
    //reversing the bool to do the toggle thing
    offOn = !offOn;
  }

  //if the toggle thing isn't happening, this sees that and makes it happen
  if(offOn == true){
    //make a terrible sound
    digitalWrite(buzzPin, HIGH);
    //turn on the LED
    analogWrite(ledPin, buzzTone);
      delay(50); //a small delay to make the fade silky smooth
     
      //this makes the fade happen. It's awesome and I'm cooler than you because I made it.
      buzzTone = buzzTone - buzzSub;
        if(buzzTone <= 20 || buzzTone >= 255){
        buzzSub = -buzzSub;
        }
  }      

  //the opposite of the first 'if' statement. If it's on, this kills it.
  if(offOn == false){
    digitalWrite(buzzPin, LOW);
    analogWrite(ledPin, 0);
  }

}
