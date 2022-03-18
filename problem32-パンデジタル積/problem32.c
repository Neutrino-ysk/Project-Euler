#include <stdio.h>
#define MAXNUM 3

int pNum[MAXNUM][6][MAXNUM];

int fact(int fNum){
    if(fNum != 1){
        return fNum * fact(fNum - 1);
    }else{
        return 1;
    }
}

//順列生成関数
void makePermutation(int hNum)
{
    int hNumNext;
    int sNum = 0;

    if(hNum < MAXNUM){
        hNumNext = hNum + 1;
        makePermutation(hNumNext);
    }

    while(sNum + 1 <= fact(hNum + 1)){
        int dNum = 0;
        
        while(dNum < hNum + 1){
            pNum[hNum][sNum][dNum] = dNum + 1;
            /*printf("%d ", hNum);
            printf("%d ", sNum);
            printf("%d, ", dNum);*/
            printf("%d", pNum[hNum][sNum][dNum]);
            dNum++;
        }
        sNum++;
        printf(" ");
    }
    printf("\n");
}

//main
int main(void)
{
    makePermutation(0);

    return 0;
}