typedef unsigned short int number4;

inline number4 Digit1(number4 x){
  return x & 0xF000;
}

inline number4 Digit2(number4 x){
  return x & 0x0F00;
}

inline number4 Digit3(number4 x){
  return x & 0x00F0;
}

inline number4 Digit4(number4 x){
  return x & 0x000F;
}

int RightPosition(number4 x, number4 y){
  z = x ^ y;
  return (Digit1(z)?1:0) + (Digit2(z)?1:0) + (Digit3(z)?1:0) + (Digit4(z)?1:0);
}

inline int WrongPosition(number4 x,number4 y){
  return RightPosition(x, y>>4|y<<12) + RightPosition(x, y>>8|y<<8) + RightPosition(x,y>>12|y<<4);
}

bool DoesRepeat(number4 x){
  return (bool) WrongPosition(x,x);
}

bool AreDigitsValid(number4 x){
  return Digit1(x)<=0x9000 && Digit2(x)<=0x0900 && Digit3(x)<=0x0090 && Digit4(x)<=0x0009;
}

bool IsValidGuess(number4 x){
  return !DoesRepeat(x) && AreDigitsValid(x);
}
