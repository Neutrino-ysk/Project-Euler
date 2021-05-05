#include <stdio.h>
#define E 100000
#define N 1000

int main(void)
{
  int digit[E];
  int max_gigit = 1;
  int move_up = 0;
  int ans = 0;

  digit[0] = 1;

  for(int n = 0 ; n < N ; n++){
    for(int i = 0 ; i < max_gigit ; i++){
      digit[i] = digit[i] * 2 + move_up;

      if(digit[i] > 9){
        move_up = digit[i] / 10;
        digit[i] = digit[i] - move_up * 10;
        if(i == max_gigit - 1){
        max_gigit++;
        }

      }else{
        move_up = 0;
      }
    }
  }

  for(int i = 0 ; i < max_gigit ; i++){
    printf("digit[%d] = %d\n", i, digit[i]);
    ans = ans + digit[i];
  }

  printf("max_digit = %d\n", max_gigit);
  printf("ans = %d\n", ans);

  return 0;
}
