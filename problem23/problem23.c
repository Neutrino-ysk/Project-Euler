#include <stdio.h>
#define MAX_NUM 28124
#define MAX_NUM_DUMMY 105
#define PNQ 4

long long int referenceNum[MAX_NUM];
long long int abundantNum[MAX_NUM];
long long int ANQ;
long long int RNQ;

long long int makeAbundantNum()
{
  long long int result = 0;
  long long int stop = 0;

  for(long long int naturalNum = 12 ; naturalNum < MAX_NUM ; naturalNum++){
    for(long long int i = 0 ; i < RNQ ; i++){
      stop = 0;
      if(naturalNum % referenceNum[i] == 0 && naturalNum / referenceNum[i] != 1){
        abundantNum[ANQ] = naturalNum;
        ANQ++;
        i = RNQ - 1;
        stop = 1;
      }
    }
    if(stop == 0){
      //全探索
      long long int divSom = 0;
      for(long long int i = 1 ; i < naturalNum / 2 + 1 ; i++){
        if(naturalNum % i == 0) divSom = divSom + i;
      }
      if(naturalNum < divSom){
        abundantNum[ANQ] = naturalNum;
        referenceNum[RNQ] = naturalNum;
        ANQ++;
        RNQ++;
      }
    }
  }
  return result;
}

void printAbundantList()
{
  for(long long int i = 0 ; i < ANQ ; i++){
    printf("abundantNum[%lld] = %lld\n", i, abundantNum[i]);
  }
}

int main(void)
{
  long long int naturalNumSum = 0;
  long long int maxAbundantNum = 0;
  long long int abundantNumSum = 0;

  referenceNum[0] = 6;
  referenceNum[1] = 28;
  referenceNum[2] = 496;
  referenceNum[3] = 8128;

  ANQ = 0;
  RNQ = 4;

  makeAbundantNum();
  printAbundantList();
  

  return 0;
}
