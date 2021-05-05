#include <stdio.h>

int main(void)
{
  long long int j = 2;
  long long int max;
  long long int a = 600851475143;

  for(long long  int i = 2 ; i <= a ; i++){
    while(i % j != 0){
      j++;
    }
    if(i == j){
      if(a % i == 0){
        printf("%ld\n", i);
        a = a/i;
        i--;
      }
    }
  }

  return 0;
}
