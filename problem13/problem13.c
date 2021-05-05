#include <stdio.h>
#include <stdlib.h>

long long int move_up(long long int ans)
{
  int ans1, ans2;

  ans1 = ans / 100000000;
  ans2 = (ans / 1000000000) * 10;
  ans = ans / 1000000000;

  if(ans1 - ans2 > 4){
    ans++;
  }
  return ans;
}

int main(void)
{
  FILE *fp;
  char fname[] = "text.txt";
  char chr;
  long long int num[5][100];
  long long int i = 0, j = 0;
  long long int exp = 1000000000;
  long long int sum = 0;
  long long int up = 0;

  fp = fopen(fname, "r");

  if(fp == NULL) {
    printf("%s file not open!\n", fname);
    return -1;
  }else{
    printf("%s file opened!\n", fname);
  }

  num[i][j] = 0;
  while((chr = fgetc(fp)) != EOF) {
    if(chr == 10){
      i = 0;
      j++;
      num[i][j] = 0;
    }else if(chr - '0' != -38){
      num[i][j] = ((chr - '0') * exp) + num[i][j];
      exp = exp / 10;
      if(exp < 1){
        //printf("num[%lld][%lld] = %lld\n", i, j, num[i][j]);
        exp = 1000000000;
        i++;
        if(i < 5){
          num[i][j] = 0;
        }
      }
    }
	}
  fclose(fp);

  for(int i = 4 ; i > -1 ; i--){
    for(int j = 0 ; j < 100 ; j++){
      sum = num[i][j] + sum;
    }
    if(i != 0){
      up = move_up(sum) / 10;
      sum = up;
    }
  }

  while(sum > 10000000000){
    sum = sum / 10;
  }

  printf("%lld\n", sum);
  return 0;
}
