/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://goo.gl/jtiYJy
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char textStringT[21];
const int charactersT  =  ((sizeof(textStringT) / sizeof(textStringT[0])) - 1);
unsigned long finishedTimeT = 0;
int ratingT = 19;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  lcd.backlight();
}


void loop() {
  scrollMessageT("TEOS animado", 0, 750);
}


void scrollMessageT(char * messageT, byte rowT, unsigned long lapseT) {
  strncpy(textStringT, messageT, sizeof(textStringT));
  if (millis() - finishedTimeT > lapseT) {
    finishedTimeT = millis();
    if (ratingT >= 0) {
      ratingT--;
      for (int iT = 0; iT < charactersT; iT++) {
        lcd.setCursor(iT, rowT);
        if (ratingT == charactersT)
          ratingT = 0;
        if (textStringT[ratingT++] != NULL)
          lcd.print(textStringT[ratingT - 1]);
        else
          lcd.print(' ');
      }
    }
    else ratingT = 19;
  }
}
