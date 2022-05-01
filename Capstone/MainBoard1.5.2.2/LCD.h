#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void LCDsetup(){
  lcd.init(); //initialize LCD 
  lcd.backlight(); //turn on LCD backlight
  lcd.clear();
  Wire.setClock(25000);
}

void LCDprintR1(String txt){
  lcd.setCursor(0, 0); // set cursor to first column, first row
  lcd.print(txt); // print message
}
void LCDprintR2(String txt){
  lcd.setCursor(0,1); // set cursor to first column, second row
  lcd.print(txt);
}
