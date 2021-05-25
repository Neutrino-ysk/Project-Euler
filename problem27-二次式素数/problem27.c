#include <stdio.h>

int prime[];

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
    int count = 1;

    for(int i = 1 ; i < 1001 ; i++){
        prime = prime_disc(i);
        if(prime != -1) count++;
    }

    for(int i = 0 ; i < count ; i++){

    }
}

int main(void)
{
    

    return 0;
}