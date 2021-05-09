#include <stdio.h>
#define ASK_ORDER_NUM 1000000
#define MAXNUM 9

int main(void)
{
    long long int digit[MAXNUM + 1];
    long long int digitOrderNum = 1;
    long long int orderNum = 0;

    for(int i = 0 ; i < MAXNUM + 1 ; i++){
        digit[i] = -1;
    }

    for(long long int j = 0 ; j < MAXNUM + 1 ; j++){
        for(long long int i = 0 ; i < MAXNUM + 1 ; i++){

            for(long long int h = 0 ; h < MAXNUM + 1 ; h++){
                if(digit[h] == i) i = MAXNUM + 1;
            }

            digitOrderNum = (MAXNUM + 1 - i) * digitOrderNum;

            if(digitOrderNum + orderNum > ASK_ORDER_NUM || digitOrderNum + orderNum == ASK_ORDER_NUM){
                digit[j] = i - 1;
                orderNum = digitOrderNum / (MAXNUM + 1 - i) + orderNum;
                i = MAXNUM + 1;
            }
        }
    }
    

    printf("%lld", digit[0]);
    printf("%lld", digit[1]);
    printf("%lld", digit[2]);
    printf("%lld", digit[3]);
    printf("%lld", digit[4]);
    printf("%lld", digit[5]);
    printf("%lld", digit[6]);
    printf("%lld", digit[7]);
    printf("%lld", digit[8]);
    printf("%lld", digit[9]);

    return 0;
}