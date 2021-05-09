#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

long long int collatz(long long int n, long long int len)
{
  //long long int known_len;

  if(n == 1){
    return len;
  }

  if(n % 2 == 0){
    n = n / 2;
    len++;
    collatz(n, len);
  }else if(n % 2 != 0){
    n = 3 * n + 1;
    len++;
    collatz(n, len);
  }
}

int main(void)
{
  long long int len;
  long long int len_max = -1;
  long long int ans;

  for(long long int i = 3 ; i < MAX ; i++){
    if(i != 4 && i != 8){
      len = collatz(i, 0);
      if(len > len_max){
        len_max = len;
        ans = i;
      }
      //printf("len[%lld] = %lld\n", i, len);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
