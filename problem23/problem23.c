#include <stdio.h>
#define MAX_NUM 28124
#define MAX_NUM_DUMMY 105
#define PNQ 4

long long int referenceNum[MAX_NUM];
long long int abundantNum[MAX_NUM];
long long int sumAbundantNum[MAX_NUM];
long long int ANQ;
long long int RNQ;
long long int ANQ_SUM;

void makeAbundantNum()
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
}

int findOutincluded(long long key)
{
  for(long long int i = 0 ; i < ANQ_SUM + 1 ; i++){
    if(sumAbundantNum[i] == key) return 1;
  }
  return 0;
}

void makeSumAbundantNum()
{
  long long int sum = 0;

  for(long long int j = 0 ; j < ANQ ; j++){
    for(long long int i = j ; i < ANQ ; i++){
      sum = abundantNum[i] + abundantNum[j];
      if(ANQ_SUM < MAX_NUM){
        if(findOutincluded(sum) == 0){
          sumAbundantNum[ANQ_SUM] = sum;
          ANQ_SUM++;
        }
      }
    }
  }
}

void printAbundantList()
{
  for(long long int i = 0 ; i < ANQ ; i++){
    printf("abundantNum[%lld] = %lld\n", i, abundantNum[i]);
  }
}

void printSumAbundantList()
{
  for(long long int i = 0 ; i < ANQ_SUM ; i++){
    printf("sumAbundantNum[%lld] = %lld\n", i, sumAbundantNum[i]);
  }
}

int main(void)
{
  referenceNum[0] = 6;
  referenceNum[1] = 28;
  referenceNum[2] = 496;
  referenceNum[3] = 8128;

  ANQ = 0;
  RNQ = 4;
  ANQ_SUM = 0;

  sumAbundantNum[0] = 0;

  makeAbundantNum();
  //printAbundantList();
  makeSumAbundantNum();
  printSumAbundantList();

  return 0;
}
