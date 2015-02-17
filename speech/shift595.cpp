#include <Arduino.h>
#include "shift595.h"

/*
595 : 
  data   14
  clock  12
  latch  11
*/

ShiftRegister::ShiftRegister(int ds/*ser*/, int st_cp/*clock*/, int sh_cp /*latch*/) {

  pinMode(ds, OUTPUT);
  pinMode(st_cp, OUTPUT);
  pinMode(sh_cp, OUTPUT);

  this->ds = ds;
  this->st_cp = st_cp;
  this->sh_cp = sh_cp;
  
  mode = LSBFIRST;
}

void ShiftRegister::msb() {
  mode = MSBFIRST;
}

void ShiftRegister::lsb() {
  mode = LSBFIRST;
}

void ShiftRegister::writeData(int data) const {
  digitalWrite(sh_cp, LOW);
  shiftOut(ds, st_cp, mode, data);
  digitalWrite(sh_cp, HIGH);
}


