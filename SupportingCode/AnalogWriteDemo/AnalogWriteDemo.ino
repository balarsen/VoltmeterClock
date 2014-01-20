// What range can the PWM output to the voltmeter?s
 
const uint8_t hourPin   = 5; // these should be revisited to see what is acutaully best
const uint8_t minutePin = 6;

void setup () {
    // set pins as outputs:
  pinMode(minutePin, OUTPUT);
  pinMode(hourPin, OUTPUT);
    Serial.begin(57600);
}
 
 uint8_t hourVal, hv;
 uint8_t minuteVal, mv;
 
void loop () {

  for (hourVal=0; hourVal<24; hourVal++) {
    for (minuteVal=0; minuteVal<60; minuteVal++) {
  
  hv = map(hourVal, 0, 23, 0, 255);
  mv = map(minuteVal, 0, 59, 0, 255);
   Serial.print(hourVal);
   Serial.print(F("  --  "));
      Serial.print(hv);
   Serial.print(F("  ::  "));

   Serial.print(minuteVal);
     Serial.print(F("  --  "));
      Serial.println(mv);
      
   analogWrite(hourPin, hv);
   analogWrite(minutePin, mv);

   
    Serial.println();
    delay(1000);
    }
  }
  
    

}
