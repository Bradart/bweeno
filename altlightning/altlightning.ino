#define BETWEEN 2579
#define DURATION 43 
#define TIMES 7

#define LEDPIN 13

unsigned long lastTime = 0;
int waitTime = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println("lightning 0.0");

  pinMode(LEDPIN, OUTPUT); 
}

void loop()
{
  if (millis() - waitTime > lastTime)  // time for a new flash
  {
    // adjust timing params
    lastTime += waitTime;
    waitTime = random(BETWEEN);

    for (int i=0; i< random(TIMES); i++)
    {
      Serial.println(millis());
      digitalWrite(LEDPIN, HIGH);
      delay(20 + random(DURATION));
      digitalWrite(LEDPIN, LOW);
      delay(10);
    }
  }
  
  // do other stuff here

}
