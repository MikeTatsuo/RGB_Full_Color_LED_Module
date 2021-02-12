#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define RED 9
#define GREEN 10
#define BLUE 11

void setLight(int col, int line, int color, int intensity) {
  lcd.setCursor(col, line);
  lcd.print(intensity);
  lcd.print("   ");
  analogWrite(color, intensity);
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("** RGB Full Color **");

  lcd.setCursor(0, 1);
  lcd.print("RED: 0");

  lcd.setCursor(0, 2);
  lcd.print("GREEN: 0");

  lcd.setCursor(0, 3);
  lcd.print("BLUE: 0");
}

void loop() {
  for(int x = 0; x <= 255; x++) {
    setLight(5, 1, RED, x);
    if (x % 2) {
      for (int y2 = 255; y2 >= 0; y2--) {
        setLight(7, 2, GREEN, y2);
        if (y2 % 2) {
          for(int z4 = 255; z4 >= 0; z4--) {
            setLight(6, 3, BLUE, z4);
          }
        } else {
          for(int z3 = 0; z3 <= 255; z3++) {
            setLight(6, 3, BLUE, z3);
          }
        }
      }      
    } else {
      for (int y1 = 0; y1 <= 255; y1++) {
        setLight(7, 2, GREEN, y1);
        if (y1 % 2) {
          for(int z2 = 255; z2 >= 0; z2--) {
            setLight(6, 3, BLUE, z2);
          }
        } else {
          for(int z1 = 0; z1 <= 255; z1++) {
            setLight(6, 3, BLUE, z1);
          }
        }
      }   
    }
  }
}
