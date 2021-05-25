#include <stdio.h>

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

void setPrimeNum()
{
    int prime;
    int count = 1;

    for(int i = 1 ; i < 1001 ; i++){
        prime = prime_disc(i);
        if(prime != -1) count++;
    }
}

int main(void)
{
    

    return 0;
}