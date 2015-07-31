
/*
 * Current reading for 12 LED (10cm) is 54mA
 *
 * LED segment pattern is:
 *
 *       1
 *   +++++++++
 *   +       +
 * 2 +       + 3
 *   +   4   +
 *   +++++++++
 *   +       +
 * 5 +       + 6
 *   +   7   +
 *   +++++++++  + 8
 */
const int datapin = 2; // MOSI / ser in
const int clockpin = 3; // SPI CSLK / srck
const int latchpin = 4; // SPI SS / rck

// Output patterns for the digits from 0 to 9
const byte NUMBER[3][10] = {
  {B01000000, B00000000, B01000000, B01000000, B00000000, B01000000, B01000000, B01000000, B01000000, B01000000},
  {B01110000, B00100000, B01101000, B01101000, B01110000, B01011000, B01010000, B00101000, B01111000, B01111000},
  {B01110111, B00100100, B01011101, B01101101, B00101110, B01101011, B01111011, B00100101, B01111111, B01101111}};

void setup() {
  // Set the three SPI pins to be outputs:
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);  
  pinMode(latchpin, OUTPUT);
}

void loop() {
  /*
 for (int i = 0; i <= 9; i++) {
  byte number1 = NUMBER[i];
  byte number2 = NUMBER[i];
  byte number3 = NUMBER[i];
  bitWrite(number1, 7, 1);
  bitWrite(number2, 7, 1);
  bitWrite(number3, 7, 1);
   shiftOut(datapin, clockpin, MSBFIRST, number1);
   shiftOut(datapin, clockpin, MSBFIRST, number2);
   shiftOut(datapin, clockpin, MSBFIRST, number3);
   shiftOut(datapin, clockpin, MSBFIRST, number1);
   shiftOut(datapin, clockpin, MSBFIRST, number2);
   shiftOut(datapin, clockpin, MSBFIRST, number3);
   digitalWrite(latchpin, HIGH);
   digitalWrite(latchpin, LOW);
 delay(1000);
 */
 for (int i = 0; i <= 9; i++) {
  for (int j= 0; j < 3; j++) {
    shiftOut(datapin, clockpin, MSBFIRST, NUMBER[j][i]);
    shiftOut(datapin, clockpin, MSBFIRST, NUMBER[j][i]);
    shiftOut(datapin, clockpin, MSBFIRST, NUMBER[j][i]);
    shiftOut(datapin, clockpin, MSBFIRST, NUMBER[j][i]);
    shiftOut(datapin, clockpin, MSBFIRST, NUMBER[j][i]);
    shiftOut(datapin, clockpin, MSBFIRST, NUMBER[j][i]);
    digitalWrite(latchpin, HIGH);
    digitalWrite(latchpin, LOW);
    delay(100);
  }
  delay(1000);
 }
}
