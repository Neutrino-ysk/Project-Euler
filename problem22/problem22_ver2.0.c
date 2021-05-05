#include <stdio.h>
#include <stdlib.h>

struct dict
{
  int num;
  char word[50];
  int nw;
  struct dict *next;
};

struct dict *new;
struct dict *top;

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

void newDict(){
  struct dict *dict;

  dict = (struct dict *)malloc(sizeof(struct dict));

  //dict->next = top;

  new = dict;
}

void insertDics(){
  if(top == NULL){
    new->next = top;
    top = new;
  }else if(top->next == NULL){
    if(compWord(new->word, new->nw, top->word, top->nw) == 0){
      new->next = top;
      top = new;
    }else{
      top->next = new;
    }
  }else{
    struct dict *dict;

    dict = top;

    while(dict->next != NULL && compWord(new->word, new->nw, dict->next->word, dict->next->nw) == 1){
      dict = dict->next;
    }
    new->next = dict->next;
    dict->next = new;
  }
}

void showList(){
  struct dict *dict;

  dict = top;

  while(dict != NULL){
    //printf("\nnum = %d : ", dict->num);
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
  FILE *fp;
  char chr;
  int bin = 0;
  //int num = 0;
  int count = 0;

  //char *chr2 = "APPLECOMP";
  //char *chr1 = "APPLE";

  //printf("%d\n", comp(chr1, 4, chr2, 8));

  fp = fopen("text.txt", "r");

  if(fp != NULL){
    printf("Open!\n");
  }else{
    printf("not open...\n");
  }

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
      //new->num = num;
      //num++;
    }
    if(bin == 1 && chr != 34){
      new->word[count] = chr;
      printf("%c\n", new->word[count]);
      count++;
      new->nw = count;
    }else{
      count = 0;

      for(int i = 0 ; i < new->nw ; i++){
        //printf("%c", new->word[i]);
      }
      printf("\n");

      insertDics();
    }
  }

  //showList();
  return 0;
}
