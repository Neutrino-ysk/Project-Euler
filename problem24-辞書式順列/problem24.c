#include <stdio.h>
#define ASK_ORDER_NUM 1000000
#define MAXNUM 9

long long int digit[MAXNUM + 1];
long long int num[MAXNUM + 1];
long long int orderNum = 0;
long long int digitCount;

long long int makeFactorial(long long int num)
{
    if(num == 1) return 1;
    return num * makeFactorial(num - 1);
}

void printDigit()
{
    for(long long int i = 0 ; i < MAXNUM + 1 ; i++){
        printf("%lld", digit[i]);
    }
}

int main(void)
{
    for(long long int i = 0 ; i < MAXNUM + 1 ; i++){
        digit[i] = -1;
        num[i] = i;
    }

    for(long long int dNum = 0 ; dNum < MAXNUM ; dNum++){
        digitCount = -1;
        while(orderNum < ASK_ORDER_NUM){
            orderNum = makeFactorial(MAXNUM - dNum) + orderNum;
            digitCount++;
            while(num[digitCount] == -1) digitCount++;
        }
        orderNum = orderNum - makeFactorial(MAXNUM - dNum);
        digitCount = digitCount;
        while(num[digitCount] == -1) digitCount--;
        digit[dNum] = num[digitCount];
        num[digitCount] = -1;        
    }

    digitCount = 0;
    while (num[digitCount] == -1) digitCount++;
    digit[MAXNUM] = num[digitCount];
    printDigit();

    return 0;
}