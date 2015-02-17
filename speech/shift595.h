
class ShiftRegister {
public:
  ShiftRegister(int ds/*ser*/, int st_cp/*clock*/, int sh_cp /*latch*/) ;
  void msb();
  void lsb();
  void writeData(int data) const;

protected:
  int ds;
  int st_cp;
  int sh_cp;
  int mode;
};

