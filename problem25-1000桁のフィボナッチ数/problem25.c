#include <stdio.h>
#define VISIBLE_DIGIT_NUM 1001
#define MAX_DIGIT 1000

int nowFib[VISIBLE_DIGIT_NUM];
int preFib[VISIBLE_DIGIT_NUM];
int upNum = 0;
int termNum = 2;

void addFibonacci()
{
    int sumFibonacci;

    for(int digit = 0 ; digit < VISIBLE_DIGIT_NUM ; digit++){
        
        if(nowFib[digit] != 0 || preFib[digit] != 0){
            sumFibonacci = nowFib[digit] + preFib[digit] + upNum;
            preFib[digit] = nowFib[digit];
            upNum = 0;
            if(sumFibonacci > 9){
                upNum = sumFibonacci / 10;
                sumFibonacci = sumFibonacci - upNum * 10;
            }
            nowFib[digit] = sumFibonacci;
        }else if(upNum != 0){
            nowFib[digit] = nowFib[digit] + upNum;
            upNum = 0;
        }
    }
}

void makeFibonacci(int maxDigitNum)
{
    while (nowFib[maxDigitNum - 1] == 0)
    {
        addFibonacci();
        termNum++;
    }
}

void printFibonacci()
{
    printf("fibonacci[%d] = ", termNum);
    for(int digit = VISIBLE_DIGIT_NUM ; digit > -1 ; digit--){
        printf("%d", nowFib[digit]);
    }
}

int main(void)
{
    int count = 0;
    preFib[0] = 1;
    nowFib[0] = 1;
    
    makeFibonacci(MAX_DIGIT);
    
    printFibonacci();
    
    return 0;
}