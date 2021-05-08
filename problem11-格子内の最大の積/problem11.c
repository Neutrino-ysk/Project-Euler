#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp;
  char fname[] = "text.txt";
  char chr;
  int n;
  int n_ten;
  int count = 0;
  int x = 59;
  int y = 20;
  int x_new = 0;
  int num[20][20];

  fp = fopen(fname, "r");

  if(fp == NULL) {
    printf("%s file not open!\n", fname);
    return -1;
  }else{
    printf("%s file opened!\n", fname);
  }

  for(int j = 0 ; j < y ; j++){
    for(int i = 0 ; i < x ; i++){
      if((chr = fgetc(fp)) != EOF){
        n = chr - '0';

        if(chr != 10){

          if(count == 0){
            n_ten = n * 10;

          }else if(count == 1){
            num[x_new][j] = n_ten + n;
            n_ten = 0;
            x_new++;
          }else if(count == 2){
            count = -1;
          }
          count++;
        }else{
          i--;
        }
      }

    }
    count = 0;
    x_new = 0;
  }

  for(int j = 0 ; j < 20 ; j++){
    for(int i = 0 ; i < 20 ; i++){
      printf("%d ", num[i][j]);
    }
    printf("\n");
  }
  fclose(fp);

  int mul;
  int max = 0;

  for(int j = 0 ; j < 20 ; j++){
    for(int i = 0 ; i < 17 ; i++){
      mul = num[i][j] * num[i + 1][j] * num[i + 2][j] * num[i + 3][j];
      if(mul > max){
        max = mul;
      }
    }
  }

  for(int i = 0 ; i < 20 ; i++){
    for(int j = 0 ; j < 17 ; j++){
      mul = num[i][j] * num[i][j + 1] * num[i][j + 2] * num[i][j + 3];
      if(mul > max){
        max = mul;
      }
    }
  }

  for(int j = 0 ; j < 17 ; j++){
    for(int i = 0 ; i < 17 ; i++){
      mul = num[i][j] * num[i + 1][j + 1] * num[i + 2][j + 2] * num[i + 3][j + 3];
      if(mul > max){
        max = mul;
      }
    }
  }

  for(int j = 0 ; j < 17 ; j++){
    for(int i = 3 ; i < 20 ; i++){
      mul = num[i][j] * num[i - 1][j + 1] * num[i - 2][j + 2] * num[i - 3][j + 3];
      if(mul > max){
        max = mul;
      }
    }
  }

  printf("max = %d", max);

  return 0;
}
