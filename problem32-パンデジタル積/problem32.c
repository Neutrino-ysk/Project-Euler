#include <stdio.h>
#define NOD 5
#define DIGIT_MAX 99999
#define SUM_DIGIT 34

int digit[10];
int oneDigit[1];
int twoDigit[2];
int threeDigit[3];
int fourDigit[4];
/*int digitSum = 0;
int digitMul = 1;
int isZero = 0;*/

void initDigit()
{
    for(int i = 0 ; i < NOD ; i++){
        digit[i] = NOD - i;
    }
}

void nextDigit()
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

int checkIsPandigital()
{
    for(int j = 0 ; j < NOD ; j++){
        for(int i = 0 ; i < NOD ; i++){
            if(i != j && digit[j] == digit[i] || digit[i] == 0) return 0;
        }
    }
    return 1;
}

int expNum(int powNum)
{
    int result = 1;
    for(int i = 0 ; i < powNum ; i++){
        result = result * 10;
    }
    return result;
}

int convertDigitNum()
{
    int result = 0;

    for(int i = 0 ; i < NOD ; i++){
        result = digit[i] * expNum(i) + result;
    }

    return result;
}

int sumDigit()
{
    int result = 0;

    for(int i = 0 ; i < NOD ; i++){
        result = digit[i] + result;
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
    initDigit();

    while(convertDigitNum() < DIGIT_MAX){
        if(sumDigit() == SUM_DIGIT){
            //printDigit();
            if(checkIsPandigital() == 1) printDigit();
        }
        //printf("checkIsPandigital = %d\n", checkIsPandigital());
        nextDigit();
    }

    return 0;
}