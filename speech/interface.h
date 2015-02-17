#define MAX_TEXT_LENGTH    32

class HOption;

class HawkingState {
  public:
    HawkingState();
    void reset();
    void update(int isPressed);
    void draw();
 
 protected:
    void switchToState(int state);
    
    //int  uiState;
    const HOption  *pCurrentState;
    char  lastWord[MAX_TEXT_LENGTH];
    char  lastLetter;
    char  text[MAX_TEXT_LENGTH];
    
    short  uiSpeed;
    short  uiSpeed2;
    long long stateEndMilli;
};

