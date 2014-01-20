// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
 
#include <Wire.h>
#include <RTClib.h>
 
RTC_DS1307 RTC;

const uint8_t hourPin   = 5; // these should be revisited to see what is acutaully best
const uint8_t minutePin = 6;

void makeISOdate(String *isodate, DateTime dt);

char isotime[19];

void setup () {
    // set pins as outputs:
  pinMode(minutePin, OUTPUT);
  pinMode(hourPin, OUTPUT);
    Serial.begin(57600);
    Wire.begin();
 
   if (RTC.isrunning()) {
    Serial.println(F("RTC is running in setup."));
   }
 
  if (! RTC.isrunning()) {
    Serial.println(F("RTC is NOT running!"));
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }

    RTC.begin();
    DateTime now = RTC.now();
  if  (now.year() == 2000) { // it wasn't set properly
        RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}

void makeISOdate(char *isodate, DateTime dt){
  sprintf(isodate, "%4d-%02d-%02dT%02d:%02d:%02d%\n",
      dt.year(), dt.month(), dt.day(), dt.hour(), dt.minute(), dt.second() );
}
 
 
 uint8_t hourVal;
 uint8_t minuteVal;
 
void loop () {
    DateTime now = RTC.now();
   makeISOdate(isotime, now);
    Serial.println(isotime);
    hourVal = map(now.hour(), 0, 23, 0, 255);
    minuteVal = map(now.minute(), 0, 59, 0, 255);
   Serial.print(hourVal);
   Serial.print(F("  --  "));
   Serial.println(minuteVal);
      
   analogWrite(hourPin, hourVal);
   analogWrite(minutePin, minuteVal);

   
    Serial.println();
    delay(5000);
}
