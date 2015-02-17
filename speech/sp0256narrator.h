
class SP0256Narrator {
public:
  SP0256Narrator(const ShiftRegister &shiftRegister, int lrqPin, int aldPin, int resetPin=0, int oscPin=0);
  
  void say(unsigned char phoneme);
  
protected:
  void handleReset(const int pin);
  void initiateOscilliator();  // no pin required, because it can only be on pin 11
  
  ShiftRegister sr;
  int ald;
  int lrq;
};

