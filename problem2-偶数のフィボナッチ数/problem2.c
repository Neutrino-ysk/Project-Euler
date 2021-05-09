#include <stdio.h>

int main(void)
{
  int fib_pre = 1;
  int fib_now = 2;
  int fib;
  int s = 0;

  while(fib < 4000000){
    fib = fib_pre + fib_now;
    if(fib % 2 == 0){
      s = s + fib;
    }
    fib_pre = fib_now;
    fib_now = fib;
  }

  printf("%d\n", s + 2);
  return 0;
}
