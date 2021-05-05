#include <stdio.h>
#define OSN 20

int main(void)
{

  long long int ans = 1;
  int div_num[OSN];
  int num;
  int n = 0;

  for(int i = 0 ; i < OSN ; i++){
    div_num[i] = OSN - i;
    //printf("div_num[%d] = %d\n", i, div_num[i]);
  }

  for(int i = OSN * 2  ; i > OSN ; i--){
    num = i;
    ans = ans * num;
    //printf("%lld\n", ans);
    for(int j = 0 ; j < OSN ; j++){
      if(ans % div_num[j] == 0 && div_num[j] != -1){
        ans = ans / div_num[j];
        //printf("ans = %lld\n", ans);
        div_num[j] = -1;
      }
    }

  }

  printf("%lld\n", ans);

  return 0;
}
