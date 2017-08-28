// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
//#include "LowPower.h"

RTC_DS1307 rtc;
int sat=0;
int minut=0;
bool prekini_zv=0;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int ledPin = 8;
int ulaz = 11;
void setup () {
   pinMode(ledPin, OUTPUT);
   pinMode(ulaz, INPUT);
  while (!Serial); // for Leonardo/Micro/Zero

  Serial.begin(57600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
     rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
     //rtc.adjust(DateTime(2017, 5, 21, 13, 53, 0));
  }
}

void loop () {
    //LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    delay( 1500); // Napraviti pametniji i efikasnije delay
    DateTime now = rtc.now();

    prekini_zv=0;
  
    sat=now.hour();
    Serial.print(sat, DEC);
    Serial.print(':');
    minut=now.minute();
    Serial.print(minut, DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();


  
// Ovo je petlja za vibraciju
    if ( sat==5 && minut>=50 && minut<=55 && prekini_zv==0 ){
       digitalWrite(ledPin, HIGH);
       //Serial.print("LED Sijaji\n");
    }
    else {
     digitalWrite(ledPin, LOW);
       //Serial.print("LED MRACI\n");
    }
    
  
    
}
