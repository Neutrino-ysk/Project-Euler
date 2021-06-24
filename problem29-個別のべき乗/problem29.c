#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A_MAX  101
#define A_MIN  2

#define B_MAX  101
#define B_MIN  2

int primeNum[100];
int pMax = 0;

int prime_disc(int i)
{
  int j = 2;

  if(j <= i) while(i % j != 0) j++;
  if(i == j) return i;

  return -1;
}

int makePrimeNum()
{
    int prime;
    int count = 0;

    for(int i = 2 ; i < A_MAX ; i++){
        prime = prime_disc(i);
        if(prime != -1){
            primeNum[count] = prime;
            count++;
        }
    }
    pMax = count - 1;
}

int* canSimplification(int a, int b)
{
    int count = 0;
    int endWhile = 0;
    int quotient;
    int exp = 0;
    int* re = NULL;

    re = (int*)malloc(sizeof(int) * 2);

    makePrimeNum();

    while (endWhile == 0){
        if(a % primeNum[count] == 0){
            if(quotient != a / primeNum[count]) endWhile = 1;
            exp++;
        }else{
            count++;
            if(count > pMax ) endWhile = 1;
        }
    }
        
    re[0] = a;
    re[1] = b;

    return re;
}

int main(void)
{
    int a = 7;
    int b = 12;
    int* re = NULL;

    re = canSimplification(a, b);

    free(re);

    return 0;
}