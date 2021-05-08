#include <stdio.h>
#define SY 1900
#define EY 2000
#define DW 1

int main(void)
{
  int startYear = SY;
  int endYear = EY + 1;
  int oneMonth_28 = 28 % 7;
  int oneMonth_29 = 29 % 7;
  int oneMonth_30 = 30 % 7;
  int oneMonth_31 = 31 % 7;
  int key;
  int dw = DW;      //0：日曜 1：月曜 2：火曜 3：水曜 4：木曜 5：金曜 6：土曜
  int leap_is = 0;
  int cal = 0;
  int ans = 0;

  for(int year = startYear ; year < endYear ; year++){
    printf("\n%d\n", year);
    if(year % 4 == 0){
      leap_is = 1;
      if(year % 400 != 0 && year % 100 == 0){
        leap_is = 0;
      }
    }else{
      leap_is = 0;
    }
    for(int month = 1 ; month < 13 ; month++){
      if(year == startYear && month == 12){
        cal = 1;
      }
      if(year == endYear - 1 && month == 12){
        cal = 0;
      }
      switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
          key = oneMonth_30;
        break;

        case 2:
          key = oneMonth_28;
          if(leap_is == 1){
              key = oneMonth_29;
            }
        break;

        default:
          key = oneMonth_31;
      }
      dw = (dw + key) % 7;
      if(cal == 1 && dw == 0){
        ans++;
        printf("//////////\n");
      }
      printf("%d:%d\n", month + 1, dw);
      //printf("%d\n", cal);
    }
  }
  printf("%d\n", ans);
  return 0;
}
