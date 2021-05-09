#include <stdio.h>
#include <string.h>

int main(void)
{
  int char_len[1001];

  char_len[1] = strlen("One");
  char_len[2] = strlen("Two");
  char_len[3] = strlen("Three");
  char_len[4] = strlen("Four");
  char_len[5] = strlen("Five");
  char_len[6] = strlen("Six");
  char_len[7] = strlen("Seven");
  char_len[8] = strlen("Eight");
  char_len[9] = strlen("Nine");
  char_len[10] = strlen("Ten");

  char_len[11] = strlen("Eleven");
  char_len[12] = strlen("Twelve");
  char_len[13] = strlen("Thirteen");
  char_len[14] = strlen("Fourteen");
  char_len[15] = strlen("Fifteen");
  char_len[16] = strlen("Sixteen");
  char_len[17] = strlen("Seventeen");
  char_len[18] = strlen("Eighteen");
  char_len[19] = strlen("Nineteen");

  char_len[20] = strlen("Twenty");
  char_len[30] = strlen("Thirty");
  char_len[40] = strlen("Forty");
  char_len[50] = strlen("Fifty");
  char_len[60] = strlen("Sixty");
  char_len[70] = strlen("Seventy");
  char_len[80] = strlen("Eighty");
  char_len[90] = strlen("Ninety");

  char_len[100] = strlen("Hundred");

  char_len[1000] = strlen("OneThousand");

  int digit[4];
  int num_len = 0;
  int and = 3;
  int ans = 0;

  for(int n = 1 ; n < 1000 ; n++){
  //int n = 1;
    for(int i = 0 ; i < 4 ; i++){
      digit[i] = 0;
    }

    if(n / 100 > 0){
      digit[3] = n / 100;
    }

    if((n - digit[3] * 100) / 10 > 0){
      digit[2] = (n - digit[3] * 100) / 10;
    }

    if((n - digit[2] * 10) > 0){
      digit[1] = ((n - digit[3] * 100) - digit[2] * 10);
    }

    if(digit[3] != 0){
      num_len = char_len[digit[3]] + char_len[100];

      if(digit[2] != 0 || digit[1] != 0){
        num_len = num_len + and;
      }
    }

    if(digit[2] != 0){
      if(digit[2] > 1){
        num_len = num_len + char_len[digit[2] * 10];
      }else{
        num_len = num_len + char_len[digit[2] * 10 + digit[1]];
        digit[1] = 0;
      }
    }

    if(digit[1] != 0){
      num_len = num_len + char_len[digit[1]];
    }

    ans = ans + num_len;
    num_len = 0;
  }
  ans = ans + char_len[1000];
  printf("ans = %d\n", ans);
  return 0;
}
