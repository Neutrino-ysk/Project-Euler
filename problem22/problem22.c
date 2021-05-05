#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

struct dict
{
  int num;
  char word[20];
  long int orderScore;
  long int nameScore;
  struct dict *next;
};

struct dict *top;

//名前を辞書順に追加
void addDict(char *word)
{
  struct dict *dict;
  struct dict *nowNode;
  struct dict *preNode;
  int stop = 0;

  dict = (struct dict *)malloc(sizeof(struct dict));
  nowNode = top;
  preNode = nowNode;

  strcpy(dict->word, word);

  if(top == NULL || (nowNode == top && strcmp(word, nowNode->word) <= 0)){//連結リストの先頭に追加する場合
    dict->next = top;
    top = dict;
  }else if(top != NULL){//連結リストの先頭以外に追加する場合
    while(stop == 0){
      if(nowNode == NULL || strcmp(word, nowNode->word) <= 0){
        //データの入力
        dict->next = nowNode;
        preNode->next = dict;
        stop = 1;
      }else{
        preNode = nowNode;
        nowNode = nowNode->next;
      }
    }
  }
}

long int calcOrderScore(char *word)
{
  long int orderScore = 0;

  for(int i = 0 ; i < strlen(word) ; i++){
    if(word[i] != '\n') orderScore = orderScore + (word[i] + 1 - 'A');
  }

  return orderScore;
}

long int calcNameScore()
{
  struct dict *dict;
  long int serialNum = 1;
  long int nameScore = 0;
  dict = top;

  while(dict != NULL){
    dict->num = serialNum;
    dict->orderScore = calcOrderScore(dict->word);
    nameScore = nameScore + dict->num * dict->orderScore;
    dict->nameScore = nameScore;
    serialNum++;
    dict = dict->next;
  }
  return nameScore;
}

void showDict()
{
  struct dict *dict;
  dict = top;

  while(dict != NULL){
    printf("%d ", dict->num);
    printf("%s", dict->word);
    printf("orderScore:%ld ", dict->orderScore);
    printf("nameScore:%ld\n", dict->nameScore);
    dict = dict->next;
  }
}

int main(void)
{
  FILE *fp_origin, *fp_edit;
  char origin_fname[] = "text.txt";
  char edit_fname[] = "text_edit.txt";
  char chr;
  char dq = '"';
  char colon = ',';
  char word[20];

  //CSV形式のテキストデータと新規のテキストデータをfopen
  fp_origin = fopen(origin_fname, "r");
  fp_edit = fopen(edit_fname, "w");
  if(fp_origin != NULL && fp_edit != NULL){
    printf("Open!\n");
  }else{
    printf("Not open...\n");
  }
  //CSVファイルを読み取り一行に名前が一つになるよう編集し新しいテキストファイルに書き出す
  while((chr = fgetc(fp_origin)) != EOF){
    if(chr != dq  && chr != colon) fprintf(fp_edit, "%c", chr);
    if(chr == colon) fprintf(fp_edit, "\n");
  }
  fclose(fp_origin);
  fclose(fp_edit);

  //編集後のファイルをfopen
  fp_edit = fopen(edit_fname, "r");
  if(fp_edit != NULL){
    printf("Open!\n");
  }else{
    printf("not open...\n");
  }

  while(fgets(word, N, fp_edit) != NULL) {
		addDict(word);
	}
  fclose(fp_edit);

  long int ans = calcNameScore();
  showDict();
  printf("%ld\n", ans);

  return 0;
}
