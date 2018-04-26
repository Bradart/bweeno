// This sketch will send out a Nikon D50 trigger signal (probably works with most Nikons)
// See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!
 
int IRledPin =  4;    // LED connected to digital pin 13
int buttonPin =2; 
// The setup() method runs once, when the sketch starts
 
void setup()   {                
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);      
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}
 
void loop()                     
{
  int buttState = digitalRead(buttonPin);
  if(buttState == LOW){
    Serial.println("Sending IR signal");
    SendPowCode();
    delay(500);
 
  //delay(10000);  // wait twenty seconds (20 seconds * 1000 milliseconds)
  }
}
 
// This procedure sends a 38KHz pulse to the IRledPin 
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
 
void SendMuteCode() {

delayMicroseconds(23456);
pulseIR(2460);
delayMicroseconds(640);
pulseIR(600);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(640);
pulseIR(1220);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(620);
pulseIR(1240);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(620);
pulseIR(620);
delayMicroseconds(620);
pulseIR(1220);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(640);
pulseIR(600);
delayMicroseconds(620);
pulseIR(620);
delayMicroseconds(600);
pulseIR(620);
delayMicroseconds(27320);
pulseIR(2440);
delayMicroseconds(640);
pulseIR(600);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(640);
pulseIR(1220);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(620);
pulseIR(1240);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(640);
pulseIR(1220);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(640);
pulseIR(600);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(620);
pulseIR(620);
delayMicroseconds(27300);
pulseIR(2460);
delayMicroseconds(620);
pulseIR(620);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(640);
pulseIR(1220);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(620);
pulseIR(1220);
delayMicroseconds(640);
pulseIR(600);
delayMicroseconds(620);
pulseIR(620);
delayMicroseconds(620);
pulseIR(1220);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(640);
pulseIR(600);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(620);
pulseIR(620);
delayMicroseconds(27300);
pulseIR(2440);
delayMicroseconds(660);
pulseIR(600);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(640);
pulseIR(1220);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(640);
pulseIR(1200);
delayMicroseconds(640);
pulseIR(600);
delayMicroseconds(620);
pulseIR(620);
delayMicroseconds(620);
pulseIR(1220);
delayMicroseconds(620);
pulseIR(600);
delayMicroseconds(640);
pulseIR(600);
delayMicroseconds(620);
pulseIR(620);
delayMicroseconds(600);
pulseIR(620);
  
}
