#include <stdio.h>
#define PRIME_RANGE 1000

int prime_disc(int i)
{
  int j = 2;

  if(j <= i){
    while(i % j != 0){
      j++;
    }
  }
  if(i == j){
    return i;
  }
  return -1;
}

int getArraySize(){
    int count = 0;

    for(int i = 1 ; i < PRIME_RANGE + 1 ; i++){
        if(prime_disc(i) != -1) count++;
    }
    return count;
}

int main(void)
{
    int arraySize = getArraySize();
    int arrayNum = 0;
    int prime[arraySize];
    int num, fn, n, a, b;
    int endLoop = 0;
    int nMax = 0;
    int aMax = 0;
    int bMax = 0;
    int result;

    for (int i = 2 ; i < PRIME_RANGE + 1 ; i++){
        num = prime_disc(i);

        if(num != -1){
            prime[arrayNum] = i;
            arrayNum++;
        }
    }

    for (b = 0; b < arraySize ; b++){
        for(a = -1000 ; a < PRIME_RANGE ; a++){
            n = 0;
            endLoop = 0;
            while (endLoop == 0){
                fn = n*n + a*n + prime[b];
                n++;
                if(prime_disc(fn) == -1) endLoop = 1;
            }
            if(nMax < n){
                nMax = n;
                aMax = a;
                bMax = b;
                result = a * prime[b];
            }
        }
    }
    printf("a = %d\n", aMax);
    printf("b = %d\n", prime[bMax]);
    printf("n = %d\n", nMax);
    printf("result = %d\n", result);

    return 0;
}