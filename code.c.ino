#include <Servo.h>
//definiamo i servomotori orizzontale e verticale
Servo servohori;
int servoh = 0;
int servohLimitHigh = 160;
int servohLimitLow = 60;

Servo servoverti; 
int servov = 0; 
int servovLimitHigh = 160;
int servovLimitLow = 60;
//Pin fotoresistenze
int ldrtopl = 2; //top left 
int ldrtopr = 1; //top right 
int ldrbotl = 3; // bottom left 
int ldrbotr = 0; // bottom right 

 void setup () 
 {
  servohori.attach(10);
  servohori.write(60);
  servoverti.attach(9);
  servoverti.write(60);
  Serial.begin(9600);
  delay(500);
  
 }

void loop()
{
  servoh = servohori.read();
  servov = servoverti.read();
  //Valore Analogico delle fotoresistenza
  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);
  // Calcoliamo una Media
  int avgtop = (topl + topr) ; //average of top 
  int avgbot = (botl + botr) ; //average of bottom 
  int avgleft = (topl + botl) ; //average of left 
  int avgright = (topr + botr) ; //average of right 

  if (avgtop < avgbot)
  {
    servoverti.write(servov +1);
    if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
    delay(10);
  }
  else if (avgbot < avgtop)
  {
    servoverti.write(servov -1);
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
    delay(10);
  }
  else 
  {
    servoverti.write(servov);
  }
  
  if (avgleft > avgright)
  {
    servohori.write(servoh +1);
    if (servoh > servohLimitHigh)
    {
    servoh = servohLimitHigh;
    }
    delay(10);
  }
  else if (avgright > avgleft)
  {
    servohori.write(servoh -1);
    if (servoh < servohLimitLow)
     {
     servoh = servohLimitLow;
     }
    delay(10);
  }
  else 
  {
    servohori.write(servoh);
  }
  delay(50);
}
