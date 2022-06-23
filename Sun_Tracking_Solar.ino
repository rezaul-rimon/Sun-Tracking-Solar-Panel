/*
  This code is for the Project of "Dual Axis Sun Tracking Solar Panel with
  Autometic Batery Charge Controller"
  This code is developed by Md. Rezaul Islam Khan, in Jan 2022.
*/

#include <Servo.h>
#include<LiquidCrystal.h>
#include<math.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); 

Servo servohori;
int servoh = 0;
int servohLimitHigh = 160;
int servohLimitLow = 20;
int tcount;
bool sw=false;


Servo servoverti;
int servov = 0;
int servovLimitHigh = 160;
int servovLimitLow = 20;

float loadi, battvol, solvol, power;

 void setup ()
 {
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  
  servohori.attach(5);
  servohori.write(90);
  servoverti.attach(6);
  servoverti.write(90);
  delay(500);
 }

void loop()
{
  servoh = servohori.read();
  servov = servoverti.read();
  //capturing analog values of each LDR
  int topl = analogRead(A3);
  int topr = analogRead(A2);
  int botl = analogRead(A1);
  int botr = analogRead(A0);
  
  
  
  
  // calculating average
  int avgtop = (topl + topr) / 8; //average of top LDRs
  int avgbot = (botl + botr) / 8; //average of bottom LDRs
  int avgleft = (topl + botl) / 8; //average of left LDRs
  int avgright = (topr + botr) / 8; //average of right LDRs

  if (avgtop > avgbot)
  {
    servoverti.write(servov +1);
    if (servov > servovLimitHigh)
     {
      servov = 100;
     }
    delay(5);
  }
  else if (avgbot > avgtop)
  {
    servoverti.write(servov -1);
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
    delay(5);
  }
  else
  {
    servoverti.write(servov);
  }
 
  if (avgleft < avgright)
  {
    servohori.write(servoh +1);
    if (servoh > servohLimitHigh)
    {
    servoh = servohLimitHigh;
    }
    delay(5);
  }
  else if (avgright < avgleft)
  {
    servohori.write(servoh -1);
    if (servoh < servohLimitLow)
     {
     servoh = servohLimitLow;
     }
    delay(5);
  }
  else
  {
    servohori.write(servoh);
  }

tcount+=1;
if(tcount>=60)
{
  sw=1-sw;
  tcount=0;
}

if(sw==0)
{
  digitalWrite(4, LOW);
  battvol = analogRead(A5);
  battvol=battvol/18;
  delay(10);
}
else
{
  digitalWrite(4, HIGH);
  solvol = analogRead(A5);
  solvol=solvol/20;
  delay(10);
}

if(solvol > battvol)
{
  digitalWrite(2, LOW);
}
else 
{
  digitalWrite(2, HIGH);
}


lcd.setCursor(0,0);
lcd.print("SV:");
lcd.print(solvol);
lcd.print("    ");
lcd.setCursor(8,0);
lcd.print("BV:");
lcd.print(battvol);
lcd.print("    ");
lcd.setCursor(0,1);
lcd.print("I:");
lcd.print(loadi);
lcd.print("    ");
lcd.setCursor(7,1);
lcd.print("P:");
lcd.print(power);
lcd.print("W");
lcd.print("   ");

delay(30);
}
