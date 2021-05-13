#include <stdio.h>
#define VISIBLE_LENGTH 5
#define MAX_DIGITNUM 10

int f1[MAX_DIGITNUM];
int f2[MAX_DIGITNUM];
int result[MAX_DIGITNUM];
int upNum = 0;

void addFibonacci()
{
    int sumFibonacci;

    for(int digit = 0 ; digit < MAX_DIGITNUM ; digit++){
        f1[digit] = f1[digit] + upNum;
        upNum = 0;
        if(f1[digit] != 0 || f2[digit] != 0){
            sumFibonacci = f1[digit] + f2[digit];
            if(sumFibonacci > 9){
                upNum = sumFibonacci / 10;
                sumFibonacci = sumFibonacci - upNum * 10;
            }
            result[digit] = sumFibonacci;
        }
    }
}

void makeFibonacci()
{
    
}

void printFibonacci()
{
    for(int digit = MAX_DIGITNUM ; digit > -1 ; digit--){
        printf("%d", result[digit]);
    }
}

int main(void)
{
    f1[0] = 5;
    f1[1] = 9;
    f2[0] = 7;
    f2[1] = 1;

    //addFibonacci();
    //printFibonacci();
    
    return 0;
}