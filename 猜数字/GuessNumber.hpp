typedef unsigned long int number4;

inline number4 Digit1(number4 x){
  return x & 0xFF000000;
}

inline number4 Digit2(number4 x){
  return x & 0x00FF0000;
}

inline number4 Digit3(number4 x){
  return x & 0x0000FF00;
}

inline number4 Digit4(number4 x){
  return x & 0x000000FF;
}

int RightPosition(number4 x, number4 y){
  z = x ^ y;
  return (Digit1(z)?1:0) + (Digit2(z)?1:0) + (Digit3(z)?1:0) + (Digit4(z)?1:0);
}

int WrongPosition(number4 x,number4 y){
  return RightPosition(x, y>>4|y<<12) + RightPosition(x, y>>8|y<<8) + RightPosition(x,y>>12|y<<4);
}
