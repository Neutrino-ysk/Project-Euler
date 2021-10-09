#include <stdio.h>

int formNum[9];
int digitNum = 2;
int digitLim = 4;
int researchNum;

int fact(int expNum)
{
    int result = 1;

    if(expNum < 1) return -1;

    for(int i = 0 ; i < expNum - 1 ; i++){
        result = result * 10;
    }

    return result;
}

int main(void)
{
    for(int i = 0 ; i < 9 ; i++){
        formNum[i] = i + 1;
    }
    
    while(digitNum <= digitLim){
        for(int digitMax = 1 ; digitMax < 10 ; digitMax++){
            for(int i = digitMax ; i < 10 ; i++){
                if(digitMax == i){
                    //printf("formNum[%d] = %d\n", i - 1, formNum[i - 1]);
                    formNum[digitMax - 1] = digitMax * fact(digitNum) + formNum[i - 1];
                    researchNum = formNum[digitMax - 1];
                    //printf("digitMax = %d\n", digitMax);
                    //printf("fact(digitNum) = %d\n", fact(digitNum));
                    //printf("formNum[%d] = %d\n", i - 1, formNum[i - 1]);
                }
                printf("%d ", researchNum);
                researchNum++;
            }
            printf("\n");
        }
        digitNum++;
    }

    

    return 0;
}