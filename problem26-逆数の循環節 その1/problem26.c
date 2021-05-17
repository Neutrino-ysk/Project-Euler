#include <stdio.h>
#define MAX_NUM 1000

int dCount = 0;
int firstAmari;
int printTrue = 0;

void division(int bunsi, int bunbo)
{   
    int amari = bunsi % bunbo;
    if(printTrue == 1) printf("%d", bunsi / bunbo);
    if(dCount == 0){
        firstAmari = amari;
        if(printTrue == 1) printf(".");
    }
    if(dCount != 0 && amari == firstAmari) amari = 0;
    dCount++;
    if(amari != 0) division((amari) * 10, bunbo);
}

int main(void)
{
    int bunbo = MAX_NUM;
    
    /*while (bunbo != dCount)
    {
        dCount = 0;
        printf("1 / %d = ", bunbo);
        division(1, bunbo);
        printf("\nD(p) = %d\n", dCount - 1);
        bunbo--;
    }*/
    bunbo = 998;
    printf("1 / %d = ", bunbo);
    division(1, bunbo);
    //printf("%d", bunbo);

    return 0;
}