/*
猜数字，10选4不重复
初始会在0-9999随机一个数并和答案比较，提供答案的大致范围
随机简单策略
*/

#include <stdio.h>
#include <string.h>
#include <random>
#include <ctime>

typedef unsigned short int number4;

number4 Candidates[10000]={};
number4 CandidatesBak[10000]={};
std::mt19937 rng(time(0));

number4 dec2bcd(number4 x){
  number4 ret;
  ret = (x / 1000) << 12;
  x = x % 1000;
  ret |= (x / 100) << 8;
  x = x % 100;
  ret |= ((x / 10) << 4) | (x % 10);
  return ret;
}

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
  number4 z = x ^ y;
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

void InitCandidatesBak(){
  CandidatesBak[0] = 0;
  number4 candidate;
  for (number4 digit1=0x0000; digit1<0xa000; digit1+=0x1000){
    for (number4 digit2=0x0000; digit2<0x0a00; digit2+=0x0100){
      if (digit2 == (digit1>>4))
        continue;
      for (number4 digit3=0x0000; digit3<0x00a0; digit3+=0x0010){
        if (digit3 == (digit1>>8) || digit3 == (digit2>>4))
          continue;
        for (number4 digit4=0x0000; digit4<0x000a; ++digit4){
          if (digit4 == (digit1>>12) || digit4 == digit2>>8 || digit4 == digit3>>4)
            continue;
          candidate = digit1 | digit2 | digit3 | digit4;
          ++CandidatesBak[0];
          CandidatesBak[CandidatesBak[0]]=candidate;
        }
      }
    }
  }
}

void InitCandidates(int lower=0x0000, int upper=0x9999){
  Candidates[0] = 0;
  for (int i=1; i<=CandidatesBak[0]; ++i){
    if (CandidatesBak[i]<lower)
      continue;
    if (CandidatesBak[i]>upper)
      return;
    ++Candidates[0];
    Candidates[Candidates[0]] = CandidatesBak[i];
  }
}

void UpdateCandidates(number4 guess, int RP, int WP){
  for (int i=Candidates[0]; i>0; --i){
    if (RightPosition(guess, Candidates[i]) != RP || WrongPosition(guess, Candidates[i]) != WP){
      Candidates[i] = Candidates[Candidates[0]];
      --Candidates[0];
    }
  }
}

int main(){
  InitCandidatesBak();
  double tries, avgtries=0;
  int samplesize=10000, feedback=100;
  number4 answer, bound, guess;
  for (int t=0; t<samplesize; ++t) {
    answer = CandidatesBak[rng()%CandidatesBak[0] + 1];
    bound = (number4) dec2bcd((number4) (rng() % 10000));
    if (answer < bound)
      InitCandidates(0, bound-1);
    else
      InitCandidates(bound,9999);
    for(tries=0.0; Candidates[0]>1; ++tries){
      guess = Candidates[rng()%Candidates[0] + 1];
      UpdateCandidates(guess, RightPosition(guess, answer), WrongPosition(guess, answer));
    }
    avgtries += tries / samplesize;
    if (t % feedback == 0)
      printf("%f%% completed.\n", (double)t / (double)samplesize * 100.0);
  }
  printf("avgtries = %f\n", avgtries);
  return 0;
}
