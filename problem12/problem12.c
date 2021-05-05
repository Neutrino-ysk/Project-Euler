#include <stdio.h>
#define Div 500

int prime_disc(int i)
{
  int j = 2;
  int bin = 0;

  while(bin == 0){
    if(j <= i){
      while(i % j != 0){
        j++;
      }
    }
    if(i == j){
      bin = 1;
      return i;
    }
    i++;
    j = 2;
  }
  return 0;
}

int div_num(int m)
{
  int p = 2;
  int i = 0;
  int div_num = 1;

  while(m != 1){
    while(m % p == 0){
      m = m / p;
      i++;
    }
    div_num = div_num * (i + 1);
    i = 0;
    p = prime_disc(p + 1);
  }
  return div_num;
}

int main(void)
{
  int t1, t2, td;
  int e = 0;

  for(int n = 1 ; e < 1 ; n++){
    if(n % 2 == 0){
      t1 = n / 2;
      t2 = n + 1;
      td = div_num(t1) * div_num(t2);
    }else{
      t1 = n;
      t2 = (n + 1) / 2;
      td = div_num(t1) * div_num(t2);
    }
    if(td > Div){
      e = 1;
    }
  }

  printf("%d\n", t1 * t2);

  return 0;
}
