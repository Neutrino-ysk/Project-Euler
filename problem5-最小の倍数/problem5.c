#include <stdio.h>

int prime(long int i)
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

int main(void)
{
  long int mul = 1;
  long int p;

  for(long int i = 2 ; i < 20 ; i++){
    long int pp = 1;
    p = prime(i);
    if(p != -1){
      while(pp < 20){
        pp = pp * p;
      }
      pp = pp / p;
    }
    mul = mul * pp;
  }
  printf("%ld\n", mul);
  return 0;
}
