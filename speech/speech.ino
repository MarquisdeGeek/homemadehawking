#include <LiquidCrystal.h>
#include "phoneme.h"
#include "processing.h"
#include "shift595.h"
#include "sp0256narrator.h"
#include "interface.h"


int pinButton = A5;
int wasDown = 0;

SP0256Narrator *g_pNarrator;
HawkingState *g_pState;
LiquidCrystal lcd(7,6,  5,4,3,2);

void trace(const char *t) {
  Serial.println(t);
}


void setup() {
  Serial.begin(115200);
  trace("Preparing...");
  
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Homemade Hawking");
  lcd.setCursor(0, 1);
  lcd.print("Marquis de Geek");
  delay(500);
  
  pinMode(pinButton,INPUT);
  
  ShiftRegister sshift(A0, 13, 12);
  g_pNarrator = new SP0256Narrator(sshift, /*lrq*/8, /*ald*/9, /*reset*/10, /*osc1*/11);
  sayHello(g_pNarrator);

  g_pState = new HawkingState();

  trace("Ready...");
}

void loop() {
  
  int isDown = analogRead(pinButton) < 100;
  int wasPressed = isDown && !wasDown;
  
  g_pState->update(wasPressed);

  wasDown = isDown;
}

