#include <stdio.h>
#define N 10000

int d(int a){

  int d = 0;

  for(int i = 1 ; i < a / 2 + 1; i++){
    if(a % i == 0){
      d = d + i;
    }
  }
  return d;
}

int main(void)
{
  int d1, d2;
  int ans = 0;

  for(int i = 1 ; i < N + 1 ; i++){
    if(i != 0){
      d1 = d(i);
      d2 = d(d1);
      if(i != d1 && i == d2){
        ans = ans + d1 + d2;
        printf("%d : %d\n", i, d(d(i)));
      }
    }
  }
  printf("%d\n", ans / 2);
//  printf("1");

  return 0;
}
