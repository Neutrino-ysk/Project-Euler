#include <stdio.h>

int palindromes(int mul, int max, int min)
{
  while(max > min){
    if((mul / max) % 10 != (mul / min) % 10){
      return -1;
    }
    max = max / 10;
    min = min * 10;
  }
  return mul;
}

int main(void)
{
  int mul;
  int ex;
  int max;
  int min;
  int palin = -1;
  int p;

  for(int i = 999 ; i > 0 ; i--){
    for(int j = i ; j > 0 ; j--){
      ex = 1;
      min = 1;
      mul = i * j;

      while(mul / ex > 1){
        ex = ex * 10;
      }
      ex = ex / 10;
      max = ex;
      p = palindromes(mul, max, min);
      if(palin < p){
        palin = p;
      }
    }
  }
  printf("%d\n", palin);
  return 0;
}
