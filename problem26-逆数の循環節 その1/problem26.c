#include <stdio.h>

int dCount = 0;
int fBunsi;
int printTrue = 1;

void division(int bunsi, int bunbo)
{   
    int amari = bunsi % bunbo;
    if(printTrue == 1) printf("%d", bunsi / bunbo);
    if(dCount == 0){
        fBunsi = bunsi;
        if(printTrue == 1) printf(".");
    }
    if(dCount != 0 && amari == fBunsi) amari = 0;
    dCount++;
    if(amari != 0) division((amari) * 10, bunbo);
}

int main(void)
{
    division(1, 11);
    printf("\nD(p) = %d", dCount - 1);

    return 0;
}