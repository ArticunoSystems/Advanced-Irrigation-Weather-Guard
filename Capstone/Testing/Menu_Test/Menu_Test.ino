#include <LiquidCrystal_I2C.h>
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

#include "BTTN.h"
#include "MENU.h"

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  BTTNSetup();

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("current level: ");
  Serial.println(curlvl);
  Serial.print("level 1: ");
  Serial.println(lvl1);
  Serial.print("level 2: ");
  Serial.println(lvl2);
  Serial.print("level 3: ");
  Serial.println(lvl3);
  Serial.print("level 4: ");
  Serial.println(lvl4);
  Serial.println();
  BTTNLoop();
  MenuLoop();
  delay(10);
}
