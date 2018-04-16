/*void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
*/

#include <IRremote.h>


const int RECV_PIN = 2;
const int sendPin = 3;
IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  //delay(3000);
  
}

void loop(){
 /* if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        Serial.println(results.decode_type);
        irrecv.resume();
  }
  //irsend.sendNEC(0x3954B1B7, 32);
  //delay(1000);
*/

if (irrecv.decode(&results)) {
    if (results.decode_type == NEC) {
      Serial.print("NEC: ");
    } else if (results.decode_type == SONY) {
      Serial.print("SONY: ");
    } else if (results.decode_type == RC5) {
      Serial.print("RC5: ");
    } else if (results.decode_type == RC6) {
      Serial.print("RC6: ");
    } else if (results.decode_type == UNKNOWN) {
      Serial.print("UNKNOWN: ");
    }
    Serial.println(results.value, DEC);
    Serial.println(results.bits);
    
    irrecv.resume(); // Receive the next value
    }
 


    
  
}

