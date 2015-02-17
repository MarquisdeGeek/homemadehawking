#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include "phoneme.h"
#include "processing.h"

// TODO: Consider moving this into/along side sp0256 since 
// the phonemes used only apply to that device
class DictionaryData {
public:
	const char *pText;
	short  index;
        short  length;
};

// TODO: Expand the dictionary
// RND: http://www.speech.cs.cmu.edu/cgi-bin/cmudict
// The phonemes are slightly different, but there's a reasonable match
// TODO: Limit the size, due to the Arduino memory with the most popular
// words, e.g. http://www.world-english.org/english500.htm
static DictionaryData dictionaryData[] = {
  {"HELLO", 0, 4},
  //
  {"F",  0, 4},  // a shortcut to test the dictionary code
  {NULL, 0,0},
};

static char dictionaryPhonemeList[] = {
/*hello*/ pHH1, pEH, pEL, pUW2, 
};



bool getPhonemeListFromDictionary(PhonemeResult &result, const char *pString) {
  int i=0;
  DictionaryData *pData = &dictionaryData[0];
     
  do {
   if (strcmp(pString, pData->pText) == 0) {
      for(int i=0;i<pData->length;++i) {
        result.add(dictionaryPhonemeList[pData->index + i]);
      }
      return true;
    }
    ++pData;
  } while(pData->pText);
  
  return false;
}

    
