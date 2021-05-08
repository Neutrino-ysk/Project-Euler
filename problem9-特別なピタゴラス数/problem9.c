#include <stdio.h>

int main(void)
{
  int mul;

  for(int a = 1 ; a < 1000 ; a++){
    for(int b = 1 ; b < 1000 ; b++){
      for(int c = 1 ; c < 1000 ; c++){
        if(a*a + b*b - c*c == 0){
          if(a + b + c == 1000){
            mul = a*b*c;
            printf("%d\n", mul);
            return 0;
          }
        }
      }
    }
  }

  return 0;
}
