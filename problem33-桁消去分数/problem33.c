#include <stdio.h>
#include <stdlib.h>

int *reduction(int a, int b)
{
    int *result = NULL;
    int divNum = 1;
    result = (int*)malloc(sizeof(int) * 2);

    while (divNum < a + 1){
        if(a % divNum == 0 && a / divNum != 1 && b % (a / divNum) == 0){
            result[0] = divNum;
            result[1] = b / (a / divNum);
            return result;
        }else if(a % divNum == 0 && a / divNum == 1 && b % divNum == 0){
            result[0] = a / divNum;
            result[1] = b / divNum;
            return result;
        }
        divNum++;
    }
    result[0] = a;
    result[1] = b;

    return result;
}

int *fakeReduction(int a, int b)
{  
    int *result = NULL;
    result = (int*)malloc(sizeof(int) * 2);

    int a1, a10, b1, b10;

    a10 = a / 10;
    a1 = a - a10 * 10;
    b10 = b / 10;
    b1 = b - b10 * 10;

    if(a1 == 0 && b1 == 0){
        result[0] = -1;
        result[1] = -1;
        return result;
    }
    
    if(a10 == b10){
        a10 = 0;
        b10 = 0;
    }else if(a10 == b1){
        a10 = 0;
        b1 = 0;
    }else if(a1 == b10){
        a1 = 0;
        b10 = 0;
    }else if(a1 == b1){
        a1 = 0;
        b1 = 0;
    }else{
        a10 = a10 * 10;
        b10 = b10 * 10;
    }

    result[0] = a10 + a1;
    result[1] = b10 + b1;

    return result;
}

int main(void)
{
    int *reductionNum = NULL;
    int *fakeReductionNum = NULL;
    int *result = NULL;
    int resultNumerator = 1;
    int resultDenominator = 1;

    //reductionNum = reduction(25, 30);
    //reductionNum = fakeReduction(30, 35);
    //printf("%d, %d\n", reductionNum[0], reductionNum[1]);
    
    for(int j = 11 ; j < 100 ; j++){
        for(int i = 10 ; i < j ; i++){
            reductionNum = reduction(i, j);
            fakeReductionNum = fakeReduction(i, j);
            if(i != fakeReductionNum[0] && j != fakeReductionNum[1]) fakeReductionNum = reduction(fakeReductionNum[0], fakeReductionNum[1]);
            if(reductionNum[0] == fakeReductionNum[0] && reductionNum[1] == fakeReductionNum[1] && i != reductionNum[0] && j != reductionNum[1]){
                resultNumerator = i * resultNumerator;
                resultDenominator = j * resultDenominator;
            }
        }
    }

    result = reduction(resultNumerator, resultDenominator);

    printf("%d, %d\n", result[0], result[1]);

    return 0;
}