#include <ctype.h>
#include "processing.h"
#include "dictionary.h"
#include "phoneme.h"

#include "shift595.h"
#include "sp0256narrator.h"

static PhonemeResult r;  // too large for local variable, it seems

static unsigned char pMapSingle[] = {
  pAE,   //A
  pBB2,   //B
  pKK1,   //C
  pDD2,   //D
  pEH,   //E
  pFF,   //F
  pGG2,   //G
  pHH1,   //H
  pIH,   //I
  pJH,   //J
  
  pKK1, // k
  pEL, // l
  pMM, // m
  pNN1, // n
  pUH, // o
  pPP, // p
  pKK3, // q
  pER2, // r
  pSS, // s
  pTT2, // t
  pUH, // u
  pVV, // v
  pWW, // w
  pAX, // x
  pYY1, // y
  pZZ, // z

};


  
static void convertWord(PhonemeResult &result, const char *pString) {
  const char *p = pString;
  
  // 1. Check dictionary
  if (getPhonemeListFromDictionary(result, pString)) {
    result.add(pPA5);
    return;
  }
  
  // 2. Attempt to built it with (addmittedly poor) logic
  char letter;
  while(*p) {
    switch(*p) {
      case ' ':
          result.add(pPA4);
          break;
      case '.':
      case ',':
          result.add(pPA5);
          break;
      default:
          letter = tolower(*p) - 'a';
          if (letter >=0 && letter < 26) {
            result.add(pMapSingle[letter]);
          }
          break;
    }

    ++p;
  }
  result.add(pPA5);
}

void sayReset() {
  r.reset();
}

void sayPhonemeList(SP0256Narrator *p) {
  
  for(int i=0;i<r.index;++i) {
    p->say(r.data[i]);
  }
}

void sayAddToPhonemeList(const char *pString) {
  // TODO: Split on spaces. Needed when the dictionary can correctly
  // handle words
  convertWord(r, pString);
}


void sayText(SP0256Narrator *p, const char *pString) {
  
  sayReset();
  
  // TODO: Split text at spaces
  sayAddToPhonemeList(pString);

  sayPhonemeList(p);
}

void sayHello(SP0256Narrator *p) {
  r.reset();
  
  r.add(pHH1);
  r.add(pEH);
  r.add(pEL);
  r.add(pUW2);
  r.add(pPA5);
  
  sayPhonemeList(p);
}


