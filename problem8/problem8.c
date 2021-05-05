#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp;
  char fname[] = "text.txt";
  char chr;
  int i = 0;
  int k;
  int d;
  long long int num[1000];
  long long int mul;
  long long int mul_max = 1;

  fp = fopen(fname, "r");

  if(fp == NULL) {
    printf("%s file not open!\n", fname);
    return -1;
  }else{
    printf("%s file opened!\n", fname);
  }

  while((chr = fgetc(fp)) != EOF) {
    if(chr - '0' != -38){
      num[i] = chr - '0';
      i++;
    }
	}

  for(int j = 0 ; j < 1000 - 12 ; j++){
    k = j;
    d = k + 13;
    mul = 1;
    while(k < d){
      //printf("num[%d] = %d\n", k, num[k]);
      mul = mul * num[k];
      k++;
    }
    //printf("mul = %lld\n", mul);
    if(mul > mul_max){
      mul_max = mul;
    }
  }
  printf("%lld\n", mul_max);
	fclose(fp);

  return 0;
}
