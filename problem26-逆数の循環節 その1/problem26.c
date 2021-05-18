#include <stdio.h>
#define MAX_NUM 1000

int dCount = 0;
int firstAmari;
int printTrue = 1;

int prime_disc(long int i)
{
  long int j = 2;

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

void division(int bunsi, int bunbo)
{
    int shou = bunsi / bunbo;
    int amari = bunsi % bunbo;
    if(printTrue == 1) printf("%d", shou);
    if(dCount == 0){
        firstAmari = amari;
        if(printTrue == 1) printf(".");
    }
    if(dCount != 0 && amari == firstAmari) amari = 0;
    dCount++;
    if(amari != 0) division((amari) * 10, bunbo);
}

int main(void)
{
    int bunbo = MAX_NUM;
    
    while (bunbo != dCount - 1)
    {
        dCount = 0;
        if(prime_disc(bunbo) != -1){
            printf("1 / %d = ", bunbo);
            division(1, bunbo);
            printf("\nD(p) = %d\n", dCount - 1);
        }        
        bunbo--;
    }
    bunbo = bunbo + 1;
    printf("result = %d", bunbo);

    return 0;
}