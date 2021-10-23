#include <stdio.h>
#define MAX_COIN_PRICE 200
#define COIN_KINDS_NUM 8

int coinKinds[8];
int maxCoinQuantity[8];
int coinQuantity[8];
int totalFee;
int skip = 0;
int result = 0;

void initCoin()
{
    int coinPrice = MAX_COIN_PRICE;
    int counter = 0;

    totalFee = 0;

    while(coinPrice > 0){
        coinKinds[counter] = coinPrice;
        maxCoinQuantity[counter] = MAX_COIN_PRICE / coinKinds[counter];
        coinPrice = coinPrice / 2;
        
        if(coinPrice > 5){
            coinPrice = coinPrice * 0.1;
            coinPrice = coinPrice * 10;
        }
        counter++;
    }

}   

void nextDigit()
{
    int addDigit = 1;

    for(int i = 0 ; i < COIN_KINDS_NUM ; i++){
        if(skip == 1) coinQuantity[i] = maxCoinQuantity[i];
        if(coinQuantity[i] == maxCoinQuantity[i] && addDigit == 1){
            coinQuantity[i] = 0;
            addDigit = 1;
        }else{
            coinQuantity[i] = coinQuantity[i] + addDigit;
            addDigit = 0;
        }     
    }
}

void calcTotalFee()
{
    for(int i = 0 ; i < COIN_KINDS_NUM ; i++){
        totalFee = coinKinds[i] * coinQuantity[i] + totalFee;
    }
}

void printDigit()
{
    for(int i = 0; i < COIN_KINDS_NUM ; i++){
        printf("%d ", coinQuantity[i]);
    }
    printf("\n");
}

int main(void)
{
    initCoin();
    
    for(int i = 0 ; i < 8 ; i++){
        printf("coinKinds[%d] = %d\n", i, coinKinds[i]);
        printf("maxCoinQuantity[%d] = %d\n\n", i, maxCoinQuantity[i]);
    }

    while(coinQuantity[7] == 0){
        totalFee = 0;
        calcTotalFee();
        //printf("totalFee = %d\n", totalFee);
        if(totalFee <= 200) result++;
        //printDigit();
        nextDigit();
        skip = 0;
    }

    printf("result = %d\n", result);

    return 0;
}