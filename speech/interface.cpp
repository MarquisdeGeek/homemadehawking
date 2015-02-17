#include <Arduino.h>
#include <LiquidCrystal.h>
#include "interface.h"
#include "processing.h"
#include "shift595.h"
#include "sp0256narrator.h"

// TODO: move these out, so the interface doesn't need this global
extern SP0256Narrator *g_pNarrator;
extern LiquidCrystal lcd;
extern void trace(const char *);

// We use chars for the values since -128 to 127 is enough, currently, and uses 1/3 of the memory.
class HOption {
  public:
  const char *pText;
  char        ifSelected;
  char        ifIdle;
  char        param;
};

#define DO_SELECT  -1
#define DO_SAY    -2
#define DO_DELETE  -3
#define DO_SPACE  -4

// TODO: Re-consider the state machine.
// Currently, I've batch the letters in un-equal groups based on likelyhood
// of the letters being needed.
static const HOption stateMachine[] = {
/*   0 */ { "ABCDE", 1, 6,   0},
/*   1 */ { "A", DO_SELECT, 2,   'A'},
/*   2 */ { "B", DO_SELECT, 3,   'B'},
/*   3 */ { "C", DO_SELECT, 4,   'C'},
/*   4 */ { "D", DO_SELECT, 5,   'D'},
/*   5 */ { "E", DO_SELECT, 0,   'E'},

/*   6 */ { "FGHIJK", 7, 13,   0},
/*   7 */ { "F", DO_SELECT, 8,   'F'},
/*   8 */ { "G", DO_SELECT, 9,   'G'},
/*   9 */ { "H", DO_SELECT, 10,   'H'},
/*  10 */ { "I", DO_SELECT, 11,   'I'},
/*  11 */ { "J", DO_SELECT, 12,   'J'},
/*  12 */ { "K", DO_SELECT,  0,   'K'},

/*  13 */ { "LMNOPQ", 14, 20,   0},
/*  14 */ { "L", DO_SELECT, 15,   'L'},
/*  15 */ { "M", DO_SELECT, 16,   'M'},
/*  16 */ { "N", DO_SELECT, 17,   'N'},
/*  17 */ { "O", DO_SELECT, 18,   'O'},
/*  18 */ { "P", DO_SELECT, 19,   'P'},
/*  19 */ { "Q", DO_SELECT,  0,   'Q'},

/*  20 */ { "RSTUVWXYZ", 21, 30,   0},
/*  21 */ { "R", DO_SELECT, 22,   'R'},
/*  22 */ { "S", DO_SELECT, 23,   'S'},
/*  23 */ { "T", DO_SELECT, 24,   'T'},
/*  24 */ { "U", DO_SELECT, 25,   'U'},
/*  25 */ { "V", DO_SELECT, 26,   'V'},
/*  26 */ { "W", DO_SELECT, 27,   'W'},
/*  27 */ { "X", DO_SELECT, 28,   'X'},
/*  28 */ { "Y", DO_SELECT, 29,   'Y'},
/*  29 */ { "Z", DO_SELECT,  0,   'Z'},

/*  30 */ { "Operations", 31, 0,   0},
/*  31 */ { "Say", DO_SAY, 32,   0},
/*  32 */ { "Space", DO_SPACE, 33,   0},
/*  33 */ { "Delete", DO_DELETE, 0,   0},

};


HawkingState::HawkingState() {

  // We vary the speed according to the option.
  // e.g. the ABCDE might need X ms, and A (on its own) has a much shorter time
  uiSpeed = 1400;
  uiSpeed2 = 800;
  
  reset();
}

void
HawkingState::reset() {
  text[0] = lastWord[0] = lastLetter = '\0';
  switchToState(0);
}

void
HawkingState::switchToState(int state) {
  
  switch(state) {
    case DO_SELECT: {
      // TODO: Check for overruns of text/lastWord
      char last[2] = {0,0};
      last[0] = lastLetter = pCurrentState->param;
      strcat(text, last);
      strcat(lastWord, last);
      switchToState(0);
    } break;
 
   case DO_SAY:
      sayText(g_pNarrator, text);
      reset();
      break;

    case DO_DELETE:  // only ever last character gets deleted
      if (strlen(text)) {
        text[strlen(text)-1] = '\0';
      }
      break;
      
    case DO_SPACE:
      lastWord[0] = '\'0';
      strcat(text, " ");
      break;
   
    default:
      pCurrentState = &stateMachine[state];
      stateEndMilli = millis();
      
      if (pCurrentState->ifSelected == DO_SELECT) {
        stateEndMilli += uiSpeed2;
      } else {
        stateEndMilli += uiSpeed;
      }
  }
  
  draw();
}

void
HawkingState::draw() {

 trace(pCurrentState->pText);
 trace(text);

 lcd.clear();
 
 lcd.setCursor(0, 0);
 lcd.print(pCurrentState->pText);
 
 lcd.setCursor(0, 1);
 lcd.print(">");
 lcd.print(text);
 lcd.print("<");

}

void
HawkingState::update(int isPressed) {
  if (isPressed) {
    switchToState(pCurrentState->ifSelected);
  } else if (millis() > stateEndMilli) {
    switchToState(pCurrentState->ifIdle);
  }
}



