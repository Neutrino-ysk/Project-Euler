#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

struct EOL_list{
  long long int num;
  long long int len;
  struct EOL_list *next;
};

//long long int point;

struct EOL_list *top;

void add_list(long long int num, long long int len)
{
  struct EOL_list *fp;

  fp = (struct EOL_list *)malloc(sizeof(struct EOL_list));

  fp->num = num;
  fp->len = len;

  fp->next = top;
  top = fp;
}

void del_list(long long int num)
{
  struct EOL_list *fp;
  struct EOL_list *dp;

  fp = top;

  while(fp->next != NULL && fp->next->num != num){
    fp = fp->next;
  }

  if(fp->next == NULL){
    return;
  }else{
    dp = fp->next;
    fp->next = dp->next;
    free(dp);
  }
}

long long int find_len(long long int num){
  struct EOL_list *fp;

  fp = top;

  while (fp != NULL && fp->num != num) {
    fp = fp->next;
  }

  if(fp != NULL){
    return fp->len;
  }else{
    return -1;
  }

}

void show_list(){
  struct EOL_list *fp;
  fp = top;
  while(fp != NULL){
    printf("\nnum = %lld\n", fp->num);
    printf("len = %lld\n", fp->len);

    fp = fp->next;
  }
}

long long int collatz(long long int n, long long int len)
{
  long long int known_len;

  if(n == 1){
    return len;
  }

  known_len = find_len(n);

  if(known_len == -1){
    add_list(n, len);
  }else{
    del_list(n);
    return len + known_len;
  }

  if(n % 2 == 0){
    n = n / 2;
    len++;
    collatz(n, len);
  }else if(n % 2 != 0){
    n = 3 * n + 1;
    len++;
    collatz(n, len);
  }
}

void reverse_len(long long int n, long long int total_len)
{
  struct EOL_list *fp;

  fp = top;

  if(find_len(n) == -1){
    return;
  }

//while(fp->next != NULL && fp->next->num != num)
  while(fp != NULL && fp->num != n){
    fp->len = total_len - fp->len;
    fp = fp->next;
  }
  if(fp != NULL){
    fp->len = total_len - fp->len;
  }
}

int main(void)
{
  long long int len;

  for(long long int i = 3 ; i < MAX ; i++){
    if(i != 4 && i != 8){
      len = collatz(i, 0);
      reverse_len(i, len);
      //printf("len[%lld] = %lld\n", i, len);
    }
  }

  //show_list();

  return 0;
}
