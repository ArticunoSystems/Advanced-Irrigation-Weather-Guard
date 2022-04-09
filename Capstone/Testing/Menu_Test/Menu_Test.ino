#include <LiquidCrystal_I2C.h>
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

#include "MENU.h"

void setup() {
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

}
