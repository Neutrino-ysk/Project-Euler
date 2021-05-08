#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp;
  int chr;
  int n;
  int n_ten;
  int count = 0;
  int x = 45;
  int y = 15;
  int x_new = 0;
  int tree_num[15][15];

  fp = fopen("text.txt", "r");

  if(fp != NULL){
    printf("file open!\n");
  }else{
    printf("not open...\n");
  }

  for(int j = 0 ; j < y ; j++){
    for(int i = 0 ; i < j * 3 + 2 ; i++){
      if((chr = fgetc(fp)) != EOF){
        n = chr - '0';

        if(chr != 10){

          if(count == 0){
            n_ten = n * 10;

          }else if(count == 1){
            tree_num[j][x_new] = n_ten + n;
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

 /*for(int j = 0 ; j < y ; j++){
    for(int i = 0 ; i < j + 1 ; i++){
      printf("%d ", tree_num[j][i]);
    }
    printf("\n");
  }*/

  for(int j = 14 ; j > 0 ; j--){
    for(int i = 0 ; i < j  ; i++){
      if(tree_num[j][i] < tree_num[j][i + 1]){
        tree_num[j - 1][i] = tree_num[j - 1][i] + tree_num[j][i + 1];
      }else{
        tree_num[j - 1][i] = tree_num[j - 1][i] + tree_num[j][i];
      }
    }
  }

  printf("%d ", tree_num[0][0]);
  fclose(fp);
  return 0;
}
