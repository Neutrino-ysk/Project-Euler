#include <stdio.h>
#define MAX_NUM 28124
#define MAX_NUM_DUMMY 105
#define PNQ 4

long long int referenceNum[MAX_NUM];
long long int abundantNum[MAX_NUM];
long long int abundantNumSum[MAX_NUM];
long long int abundantSum;
long long int naturalNumSum;
long long int result;
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
    if(abundantNumSum[i] == key) return 1;
  }
  return 0;
}

void makeabundantNumSum()
{
  long long int sum = 0;

  for(long long int j = 0 ; j < ANQ ; j++){
    for(long long int i = j ; i < ANQ ; i++){
      sum = abundantNum[i] + abundantNum[j];
      if(sum < MAX_NUM - 1){
        abundantNumSum[sum] = sum;
      }
    }
  }

  for(long long int i = 0 ; i < MAX_NUM ; i++){
    abundantSum = abundantNumSum[i] + abundantSum;
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
  for(long long int i = 0 ; i < MAX_NUM ; i++){
    printf("abundantNumSum[%lld] = %lld\n", i, abundantNumSum[i]);
  }
}

void makenaturalNumSum(long long int maxNum){
  naturalNumSum = (maxNum * (maxNum + 1)) / 2;
}

int main(void)
{
  referenceNum[0] = 6;
  referenceNum[1] = 28;
  referenceNum[2] = 496;
  referenceNum[3] = 8128;

  ANQ = 0;
  RNQ = 4;
  ANQ_SUM = 24;

  abundantNumSum[0] = 0;
  abundantSum = 0;

  makeAbundantNum();
  //printAbundantList();
  makeabundantNumSum();
  //printSumAbundantList();
  makenaturalNumSum(MAX_NUM - 2);
  printf("nuturalNumSum = %lld", naturalNumSum);
  result = naturalNumSum - abundantSum;
  printf("naturalNumSum : %lld\n", naturalNumSum);
  printf("abundantSum : %lld\n", abundantSum);
  printf("result = %lld", result);

  return 0;
}
