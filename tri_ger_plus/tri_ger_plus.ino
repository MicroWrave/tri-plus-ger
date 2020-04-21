/**
ATMEGA328 AU pin configuration & assignment
* 1  pd3 - top button
* 2  pd4 - left button
* 3  GND
* 4  VCC
* 5  GND
* 6  VCC
* 7  pb6 - crystal 1
* 8  pb7 - crystal 2
* 9  pd5
* 10 pd6
* 11 pd7
* 12 pb0
* 13 pb1
* 14 pb2
* 15 pb3 MOSI
* 16 pb4 MISO
* 17 pb5 SCK
* 18 AVCC
* 19 adc6 - roll rate
* 20 AREF
* 21 GND
* 22 adc7 - ?
* 23 pc0 adc0
* 24 pc1 adc1 - play/pause
* 25 pc2 adc2 - retrigger
* 26 pc3 adc3 - roll
* 27 pc4 adc4 - ?
* 28 pc5 adc5 - ?
* 29 pc6 RESET
* 30 pd0
* 31 pd1
* 32 pd2 - right button
*/


#define clockOut_pin 7

#define rightButton_pin 2
#define rightButtonAGAIN_pin 5
#define topButton_pin   3
#define topButtonAGAIN_pin 0
#define leftButton_pin  4

#define altButton 6

#define playPause_analog 1
#define retrigger_analog 2
#define roll_analog      3
//analog 4 not used?


int search_start = 0;
int search_end = 0;

int t = 1000;

void setup(){
  for (int i=search_start; i<=search_end; i++) {
    pinMode(i, INPUT);
  }
  pinMode(clockOut_pin, OUTPUT);
}

void digitalProbe(){
  for (int i=search_start; i<=search_end; i++) {
    digitalWrite(i, HIGH);
    delay(t/2);
    digitalWrite(i, LOW);
    delay(t/2);
  }
}

void analogBlink(){
  int a = analogRead(7);
  digitalWrite(clockOut_pin, HIGH);
  delay( a + 20 );
  digitalWrite(clockOut_pin, LOW);
  delay( a + 20 );
}

void loop() {
  bool on = false;
  for (int i=search_start; i<=search_end; i++) {
    on |= digitalRead(i);
  }
  digitalWrite(clockOut_pin, on);
}
