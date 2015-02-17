// SPO-256-AL2 phonemes
// From http://nsd.dyndns.org/speech/
enum {
  // Silence
  pPA1 = 0x00, // before BB,DD,GG,JH (10 msec)
  pPA2 = 0x01, // before BB,DD,GG,JH (30 msec)
  pPA3 = 0x02, // before PP,TT,KK,CH and between words (50 msec)
  pPA4 = 0x03, // between clauses and sentences (100 msec)
  pPA5 = 0x04, // between clauses and sentences (200 msec)
  
  // Short Vowels
  pIH  = 0x0c, // sIt
  pEH  = 0x07, // End, gEntlemen, Extend
  pAE  = 0x1a, // hAt, extrAct, Act
  pUH  = 0x1e, // bOOk, cOOkie, fUll
  pAO  = 0x17, // tALk, sOng, AUght
  pAX  = 0x0f, // sUCCeed, lApel, intrUCt
  pAA  = 0x18, // hOT, pOTtery, cOTen

  // Long Vowels
  pIY  = 0x13, // sEE, trEAt, pEOple, pEnny
  pEY  = 0x14, // bEIge, grEAt, stAte, trAY
  pAY  = 0x06, // skY, kIte, mIGHty
  pOY  = 0x05, // bOY, nOIse, vOIce
  pUW1 = 0x16, // compUter (after clusters with YY)
  pUW2 = 0x1f, // fOOd, tWO (monosyllabic words)
  pOW  = 0x35, // zOne, clOse, snOW, bEAU
  pAW  = 0x20, // OUt, sOUnd, mOUse, dOWn
  pEL  = 0x3e, // saddLE, littLE, angLE, gentLEmen

  // R-Colored Vowels
  pER1 = 0x33, // lettER, furnitURE, intERRupt
  pER2 = 0x34, // bIRd, fERn, bURn (monosyllabic words)
  pOR  = 0x3a, // stORe, adORn, fORtune
  pAR  = 0x3b, // alARm, fARm, gARment
  pYR  = 0x3c, // clEAR, EARring, IResponsible
  pXR  = 0x2f, // repaiR, haiR, declaRE, staRE

  // Resonants
  pWW  = 0x2e, // Wool, We, lingUIst
  pRR1 = 0x0e, // Rural, WRite, x-Ray (initial position)
  pRR2 = 0x27, // bRain, bRown, gRease (initial clusters)
  pLL  = 0x2d, // Lake, Like, heLLo, steeL
  pYY1 = 0x31, // cUte, bEAUty, compUter (clusters)
  pYY2 = 0x19, // Yes, Yarn, Yo-Yo (initial position)

  // Voiced Fricatives
  pVV  = 0x23, // Vest, proVE, eVen
  pDH1 = 0x12, // THis, THen, THey (initial position)
  pDH2 = 0x36, // baTHe, baTHing (word-final and between vowels)
  pZZ  = 0x2b, // Zoo, phaSE
  pZH  = 0x26, // aZure, beiGE, pleaSUre

  // Voiceless Fricatives
  pFF  = 0x28, // Food (can be doubled for initial position)
  pTH  = 0x1d, // THin (can be doubled for initial position)
  pSS  = 0x37, // Snake, veSt (can be doubled for initial position)
  pSH  = 0x25, // SHip, SHirt, leaSH, naTion
  pHH1 = 0x1b, // He (before front vowels YR,IY,IH,EY,EH,XR,AE)
  pHH2 = 0x39, // Hoe (before back vowels UW,UH,OW,OY,AO,OR,AR)
  pWH  = 0x30, // WHig, WHite, tWenty
  
  // Voiced Stops
  pBB1 = 0x1c, // riB, fiBBer, (in clusters) BLeed, BRown
  pBB2 = 0x3f, // Business, Beast (initial position before vowel)
  pDD1 = 0x15, // coulD, playeD, enD (final position)
  pDD2 = 0x21, // Do, Down, Drain (initial position and clusters)
  pGG1 = 0x24, // Got (before high front vowels YR,IY,IH,EY,EH,XR)
  pGG2 = 0x3d, // GUest, Glue, Green (before high back vowels UW,UH,OW,OY,AX)
  pGG3 = 0x22, // wiG, anGer (before low vowels AE,AW,AY,AR,AA,AO,OR,ER)
  
  // Voiceless Stops
  pPP  = 0x09, // Pow, triP, amPle, Pleasure
  pTT1 = 0x11, // parTs, tesTs, iTs (final cluster before SS)
  pTT2 = 0x0d, // To, TesT, sTreeT (all positions except before final SS)
  pKK1 = 0x2a, // Can't, Cute, Clown, sCream (before front vowels YR,IY,IH,EY,EH,XR,AY,AE,ER,AX and initial clusters)
  pKK2 = 0x29, // speaK, tasK (final position or final cluster)
  pKK3 = 0x08, // Comb, QUick, Crane, sCream (before back vowels UW,UH,OW,OY,OR,AR,AO and initial clusters)
  
  // Affricates
  pCH  = 0x32, // CHurCH, feaTure
  pJH  = 0x0a, // JudGE, inJUre, dodGE
  
  // Nasal
  pMM  = 0x10, // Milk, alarM, aMple
  pNN1 = 0x0b, // thiN, earN (before front and central vowels YR,IY,IH,EY,EH,XR,AE,ER,AX,AW,AY, and final clusters)
  pNN2 = 0x38, // No (before back vowels UH,OW,OY,OR,AR,AA)
  pNG  = 0x2c, // striNG, aNGer, aNchor
};
