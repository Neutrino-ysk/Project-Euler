#include <stdio.h>
#include <stdlib.h>

//dictの内容
struct dict
{
  int num;      //アルファベット順のときの先頭からの位置
  char word[50];//単語
  int nw;       //文字数
  struct dict *next;
};

struct dict *top;
FILE *fp;
int dict_length = 0;

void openFile(char *filename){
  fp = fopen(filename, "r");

  if(fp != NULL){
    printf("Open!\n");
  }else{
    printf("not open...\n");
  }
}

void newDict(){
  struct dict *dict;

  dict = (struct dict *)malloc(sizeof(struct dict));

  dict->next = top;
  top = dict;

  dict_length++;
}

void readWord(){
  char chr;
  int bin = 0;
  int num = 0;
  int count = 0;

  while((chr = fgetc(fp)) != EOF){
    if(chr == 34){
      if(bin == 0){
        bin = 1;
      }else{
        bin = 0;
      }
    }

    if(bin == 1 && chr == 34){
      newDict();
      top->num = num;
    }
    if(bin == 1 && chr != 34){
      top->word[count] = chr;
      count++;
      top->nw = count;
    }else{
      count = 0;
    }
  }
}

int compWord(char *word1, int nw1, char *word2, int nw2){
  int i = 0;
  int length = nw1;

  if(length > nw2){
    length = nw2;
  }

  while(i < length){
    if(word1[i] > word2[i]){
      return 1;
    }else if(word1[i] == word2[i]){
      i++;

      if(i == length){
        if(nw1 > nw2){
          //printf("Hello");
          return 1;
        }else{
          return 0;
        }
      }
    }else{
      return 0;
    }
  }

  return 0;
}

/*void sortDict(){
  struct dict *dict;

  dict = top;
  dict = dict->next;

  compWord(top->word, top->nw, dict->word, dict->nw);
}*/

void showList(){
  struct dict *dict;

  dict = top;

  while(dict != NULL){
    printf("\nnum = %d : ", dict->num);
    //printf("%d\n", dict->nw);
    for(int i = 0 ; i < dict->nw ; i++){
      printf("%c", dict->word[i]);
    }
    printf("\n");
    dict = dict->next;
  }
}

int main(void)
{
  openFile("text.txt");
  readWord();

  for(int i = 1 ; i < dict_length + 1 ; i++){
    struct dict *dict;
    struct dict *now;

    dict = top->next;
    now = top;

    while(dict != NULL){
      if(compWord(now->word, now->nw, dict->word, dict->nw) == 1 && dict->num == 0){
        now = dict;
      }
      dict = dict->next;
    }

    now->num = i;
    printf("%s\n", now->word);
  }


  //showList();

  return 0;
}
