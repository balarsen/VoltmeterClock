
// These constants won't change.  They're used to give names
// to the pins used:
const int hourPin = 2; // these should be revisited to see what is acutaully best
const int minutePin = 3;

void setup() {
  // set pins as outputs:
  pinMode(minutePin, OUTPUT);
  pinMode(hourPin, OUTPUT);
}

void loop() {
  // iterate over the pins:
  for (int thisPin = hourPin; thisPin <= minutePin; thisPin++) { 
    // fade the LED on thisPin from off to brightest:
    for (int brightness = 0; brightness < 255; brightness++) {
      analogWrite(thisPin, brightness);
      delay(2);
    } 
    // fade the LED on thisPin from brithstest to off:
    for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(thisPin, brightness);
      delay(2);
    } 
    // pause between LEDs:
    delay(100);
  }
}
