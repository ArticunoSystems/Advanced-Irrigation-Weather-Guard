#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void LCDsetup(){
  lcd.init(); //initialize LCD 
  lcd.backlight(); //turn on LCD backlight 
}

void LCDloop(){
  lcd.setCursor(0, 0); // set cursor to first column, first row
  lcd.print("Hello, World!"); // print message
  delay(1000);
  lcd.clear(); // clears the display to print new message
  lcd.setCursor(0,1); // set cursor to first column, second row
  lcd.print("Hello, World!");
  delay(1000);
  lcd.clear(); 
}
