class SP0256Narrator;
typedef  unsigned char  tBYTE;


#define MAX_PHONEME_SIZE    64

class PhonemeResult {
  public:
    tBYTE    data[MAX_PHONEME_SIZE];
    int      index;
    
    PhonemeResult() {
      reset();
    }
    
    void reset() {
        index = 0;
    }

    void add(const tBYTE p) {
      if (index < MAX_PHONEME_SIZE) {
        data[index++] = p;
      }
    }    
};


void sayReset();
void sayAddToPhonemeList(const char *pString);
void sayPhonemeList(SP0256Narrator *p);
void sayText(SP0256Narrator *p, const char *pString);

// Demo word
void sayHello(SP0256Narrator *p);

