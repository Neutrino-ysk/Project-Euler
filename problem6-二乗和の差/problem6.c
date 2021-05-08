#include <stdio.h>

int main(void)
{
  long int a = 0;
  long int b = 1;

  for(long int i = 0 ; i < 101 ; i++){
    a = a + i*i;
  }

  b = (1 + 100) * 50;
  b = b * b;

  printf("%ld\n", b - a);

  return 0;
}
