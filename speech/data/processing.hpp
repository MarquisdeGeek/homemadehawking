
#if 1
void convertWord(PhonemeResult *pResult, char *pString) {
  const char *p = pString;
  
  while(*p) {
    ++p;
  }
  
}

void processText(PhonemeResult *pResult, char *pString) {
  const char *p = pString;
  
  while(*p) {
        ++p;
  }
  result->add(pHH1);
  result->add(pEH);
  result->add(pEL);
  result->add(pUW2);
  //
  result->add(pPA5);

}

void sayPhoneme(PhonemeResult *pData) {
  for(int i=0;i<pData->index;++i) {
    say(pData->data[i]);
  }
}

void sayText(char *pString) {
  PhonemeResult r;  // Q. too large for local?
  
  processText(&r, pString);
  sayPhoneme(&r);
}
#endif
