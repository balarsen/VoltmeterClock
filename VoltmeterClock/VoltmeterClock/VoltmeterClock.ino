// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
 
#include <Wire.h>
#include <RTClib.h>
 
RTC_DS1307 RTC;

void makeISOdate(String *isodate, DateTime dt);

char isotime[19];


float hour2val(int hour) {
   return hour/24. * 5. ;  // scale the hour to 1 then 5 volts
}

float minute2val(int minute) {
  return minute/60. * 5;  // scale the hour to 1 then 5 volts
}


void setup () {
    Serial.begin(57600);
    Wire.begin();
 
   if (RTC.isrunning()) {
    Serial.println("RTC is running in setup.");
   }
 
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }

    RTC.begin();
    DateTime now = RTC.now();
  if  (now.year() == 2000) { // it wasnot set properly
        RTC.adjust(DateTime(__DATE__, __TIME__));
  }
 
}

void makeISOdate(char *isodate, DateTime dt){
  sprintf(isodate, "%4d-%02d-%02dT%02d:%02d:%02d%\n",
      dt.year(), dt.month(), dt.day(), dt.hour(), dt.minute(), dt.second() );
}
 
void loop () {
    DateTime now = RTC.now();
   makeISOdate(isotime, now);
    Serial.println(isotime);
   Serial.print(hour2val(now.hour()));
   Serial.print("  --  ");
   Serial.println(minute2val(now.minute()));
   
   
    Serial.println();
    delay(3000);
}
