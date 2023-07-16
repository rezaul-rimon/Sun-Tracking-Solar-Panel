#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#include <Wire.h>
#include <I2C_RTC.h>
static DS3231 RTC;

#include <SPI.h>
#include <SD.h>
File myFile;

#include<Servo.h>
Servo servo;

int top, bottom, pos=90, lc=500;
float sv=0;

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();

  servo.attach(9);

  RTC.begin();
  RTC.setHourMode(CLOCK_H24);


  //RTC.setDate(22,07,29);
  //RTC.setTime(22,10,20);
  //RTC.setWeek(2);

//  if (!SD.begin(8)) {
//    Serial.println("initialization failed!");
//    while (1);
//  }
//  else Serial.println("initialization done.");

if(SD.begin(8))
{
  lcd.setCursor(10,1);
  lcd.print("SD InD");
}
else
{
  lcd.setCursor(10,1);
  lcd.print("SD InP");
}

  ////Open file to write to something...
//  myFile = SD.open("test.txt", FILE_WRITE);
//
//  if (myFile) {
//    Serial.print("Writing to test.txt...");
//    myFile.println("solar tracker project");
//    myFile.close();
//    Serial.println("done.");
//    
//  } else {
//    Serial.println("error opening test.txt");
//  }


//
//  // re-open the file for reading:
//  myFile = SD.open("test.txt");
//  if (myFile) {
//    Serial.println("test.txt:");
//
//    while (myFile.available()) {
//      Serial.write(myFile.read());
//    }
//    myFile.close();
//  } else {
//    // if the file didn't open, print an error:
//    Serial.println("error opening test.txt");
//  }
//}
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  //Serial.begin(9600);
  

}

void loop() {
  sv = analogRead(A0)*0.0147;
  top = analogRead(A1)/10;
  bottom = analogRead(A2)/10;

  if(top > bottom)
  {
    pos++;
    if(pos>=180) pos=180;
    servo.write(pos);
  }

  else if(top < bottom)
  {
    pos--;
    if(pos<=0) pos=0;
    servo.write(pos);
  }

  String Time = String(RTC.getHours())+":"+String(RTC.getMinutes())+":"+String(RTC.getSeconds());
  int yr = RTC.getYear()-2000;
  String Date = String(RTC.getDay())+"/"+String(RTC.getMonth())+"/"+String(yr);
  //Serial.println(Time);

  lcd.setCursor(1,0);
  lcd.print(Date);
  lcd.print(" ");
  lcd.print(Time);

  lcd.setCursor(0,1);
  lcd.print("    ");
  lcd.setCursor(0,1);
  lcd.print(sv,2);
  lcd.print(" ");

  lcd.setCursor(6,1);
  lcd.print("   ");
  lcd.setCursor(6,1);
  lcd.print(pos);
  lcd.print(" ");
//
//  lcd.setCursor(10,1);
//  lcd.print("    ");
//  lcd.setCursor(10,1);
//  lcd.print(bottom);

  lc++;
  if(lc>=450)
  {
    lc=0;
    //Open file to write to something...
    myFile = SD.open("test.txt", FILE_WRITE);

    if (myFile) {
      //Serial.print("Writing to test.txt...");
      String Data = Date+" "+Time+" "+String(pos)+" "+String(sv);
      myFile.println(Data);
      myFile.close();
      lcd.setCursor(10,1);
      lcd.print("Wr Dn ");
      delay(5000);
      lcd.setCursor(10,1);
      lcd.print("Ftch D");
    } 
    else
    {
      //Serial.println("error opening test.txt");
      lcd.setCursor(10,1);
      lcd.print("Wr Prb ");
    }
  }
  
  delay(100);

}
