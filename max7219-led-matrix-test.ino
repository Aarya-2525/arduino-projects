#include <LedControl.h>

// DIN, CLK, CS (LOAD)
LedControl lc = LedControl(11, 13, 10, 1);  // DataIn, CLK, LOAD/CS, 1 device

void setup() {
  lc.shutdown(0, false);      // Wake up display
  lc.setIntensity(0, 1);      // Set brightness (0-15)
  lc.clearDisplay(0);         // Clear display
}
void diagonal1(){
  lc.clearDisplay(0); 
  // Light up a diagonal pattern '\'
  for (int i = 0; i < 8; i++) {
    lc.setLed(0, i, i, true); // device 0, row i, column i, ON
  }
}
void diagonal2(){
  lc.clearDisplay(0); 
  // Light up a diagonal pattern '/'
  for (int i = 0; i < 8; i++) {
    lc.setLed(0, i, 7-i, true); // device 0, row i, column 7-i, ON
  }
}
void loop() {
  diagonal1();
  delay(2000);
  diagonal2();
  delay(2000);
}
