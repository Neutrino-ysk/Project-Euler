#include <stdio.h>
#define NOD 7
#define EXP 5

int digit[NOD];
int splitDigitNum[NOD];
int maxNum = 1;

void initDigit()
{
    for(int i = 0 ; i < NOD ; i++){
        digit[i] = 0;
        maxNum = maxNum * 10;
    }
}

void nextNum()
{
    int addDigit = 1;

    for(int i = 0 ; i < NOD ; i++){
        if(digit[i] == 9 && addDigit == 1){
            digit[i] = 0;
            addDigit = 1;
        }else{
            digit[i] = digit[i] + addDigit;
            addDigit = 0;
        }        
    }
}

int researchJudgment()
{
    for(int i = 0 ; i < NOD - 1 ; i++){
        if(digit[i] < digit[i + 1]){
            return 1;
        }
    }
    return 0;
}

int expNum(int radix)
{
    int result = 1;
    for(int i = 0 ; i < EXP ; i++){
        result = result * radix;
    }
    return result;
}

int splitDigit(int num)
{
    if(num >= maxNum) return 1;
    int divNum = maxNum / 10;
    for(int i = NOD - 1 ; i > -1 ; i--){
        splitDigitNum[i] = num / divNum;
        //printf("sp = %d\n", splitDigitNum[i]);
        num = num - splitDigitNum[i] * divNum;
        divNum = divNum / 10;
    }
    return 0;
}

int checkEqualComponent()
{
    int isEqual = 0;
    
    for(int i = 0 ; i < NOD ; i++){
        isEqual = 0;
        for(int j = 0 ; j < NOD ; j++){
            if(digit[i] == splitDigitNum[j]){
                splitDigitNum[j] = -1;
                j = NOD;
                isEqual = 1;
            }
        }
        if(isEqual == 0) return -1;
    }
    return 1;
}

int calcNum()
{
    int result = 0;
    for(int i = 0 ; i < NOD ; i++){
        result = expNum(digit[i]) + result;
    }
    return result;
}

void printDigit()
{
    for(int i = NOD - 1 ; i > -1 ; i--){
        printf("%d", digit[i]);
    }
    printf("\n");
}

int main(void)
{
    int calcResult;
    int result = 0;
    initDigit();
    
    for(int i = 0 ; i < maxNum ; i++){
        calcResult = calcNum();
        if(researchJudgment() == 0 && splitDigit(calcResult) == 0 && checkEqualComponent() == 1){
            if(calcResult != 0 && calcResult != 1){
                printDigit();
                printf("calc = %d\n\n", calcResult);
                result = calcResult + result;
            }            
        }
        nextNum();
    }
    printf("result = %d\n", result);
    return 0;
}