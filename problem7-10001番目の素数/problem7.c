#include <stdio.h>

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

int main(void)
{
  int j = 0;
  int prime;

  for(long int i = 0 ; j < 10001 ; i++){
    prime = prime_disc(i);
    if(prime != -1){
      j++;
    }
  }
  printf("%d\n", prime);

  return 0;
}
