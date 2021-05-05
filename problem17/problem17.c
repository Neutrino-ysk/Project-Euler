#include <stdio.h>

int main(void)
{
  int char_len[1001];
  int one_nine = 0;
  int eleven_nineteen = 0;
  int twenty_ninety = 0;
  int twenty_ninetynine;
  int one_ninetynine;
  int hundred_thousand;
  int and = 3;
  int ans;

  //one, eleven
  char_len[1] = 3;
  char_len[11] = 6;

  //two, twelve, twenty
  char_len[2] = 3;
  char_len[12] = 6;
  char_len[20] = 6;

  //three, thirteen, thirty
  char_len[3] = 5;
  char_len[13] = 8;
  char_len[30] = 6;

  //four, fourteen, forty
  char_len[4] = 4;
  char_len[14] = 8;
  char_len[40] = 5;

  //five, fifteen, fifty
  char_len[5] = 4;
  char_len[15] = 7;
  char_len[50] = 5;

  //six, sixteen, sixty
  char_len[6] = 3;
  char_len[16] = 7;
  char_len[60] = 5;

  //seven, seventeen, seventy
  char_len[7] = 5;
  char_len[17] = 9;
  char_len[70] = 7;

  //eight, eighteen. eighty
  char_len[8] = 5;
  char_len[18] = 8;
  char_len[80] = 6;

  //nine, nineteen, ninety
  char_len[9] = 4;
  char_len[19] = 8;
  char_len[90] = 6;

  //ten, one hundred, one thousand
  char_len[10] = 3;
  char_len[100] = 7;
  char_len[1000] = 11;

  for(int i = 1 ; i < 10 ; i++){
    one_nine = one_nine + char_len[i];
  }

  printf("1~9 = %d\n", one_nine);

  for(int i = 11 ; i < 20 ; i++){
    eleven_nineteen = eleven_nineteen + char_len[i];
  }

  printf("11~19 = %d\n", eleven_nineteen);

  for(int i = 2 ; i < 10 ; i++){
    twenty_ninety = twenty_ninety + char_len[i * 10];
  }

  printf("20~90 = %d\n", twenty_ninety);

  twenty_ninetynine = twenty_ninety * 10 + one_nine * 8;

  printf("20~99 = %d\n", twenty_ninetynine);

  one_ninetynine = one_nine + char_len[10] + eleven_nineteen + twenty_ninetynine;
  printf("1~99 = %d\n", one_ninetynine);

  hundred_thousand = (one_nine + char_len[100]) * 100 + (one_ninetynine + and) * 9 + char_len[1000];
  printf("100~1000 = %d\n", hundred_thousand);

  ans = one_ninetynine + hundred_thousand;
  printf("%d\n", ans);

  return 0;
}
