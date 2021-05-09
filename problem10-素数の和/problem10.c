#include <stdio.h>
#include <math.h>

int prime_disc(int i)
{
  int j = 2;
  //int prime;

  if(j <= sqrt(i)){
    while(i % j != 0){
      j++;
    }
  }

  if(j > sqrt(i)){
    return i;
  }
  return -1;
}

int main(void)
{
  int p;
  long long int p_total = 0;
  long int s = 2000000;
  for(int i = 2 ; i < s ; i++){
    p = prime_disc(i);
    if(p != -1){
      p_total = p_total + p;
      //p_total = p;
    }

  }
  printf("%lld\n", p_total);

  return 0;
}
