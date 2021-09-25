#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A_MAX  100
#define A_MIN  2

#define B_MAX  100
#define B_MIN  2

//指数を単純化する関数
double *canSimplification(double a, double b)
{
    double* re = NULL;
    re = (double*)malloc(sizeof(double) * 2);

    double* re2 = NULL;
    double dResult = 100;
    int count = 2;
    double exp;
    int iResult;

    while(dResult > 2){
        exp = 1.0 / count;
        dResult = pow(a, exp);
        iResult = dResult;
        if(iResult == dResult && iResult < A_MAX + 1 && count * b < B_MAX + 1){
            re[0] = iResult;
            re[1] = count * b;
            re2 = canSimplification(re[0], re[1]);
            return re2;
        }
        count++;
    }
    re[0] = a;
    re[1] = b;
    return re;
}

int main(void)
{
    double* re = NULL;
    int countNum = 0;
    double result = 0.0;
    int aInt, bInt;
   
    for(double  a = A_MIN ; a < A_MAX + 1 ; a++){
        for(double  b = B_MIN ; b < B_MAX + 1 ; b++){
            aInt = a;
            bInt = b;
            printf("(%d, %d) = ", aInt, bInt);
            re = canSimplification(a, b);
            aInt = re[0];
            bInt = re[1];
            printf("(%d, %d)", aInt, bInt);
            if(re[0] == a && re[1] == b){
                printf("+");
                countNum++;
            }
            printf("\n");
        }
        printf("%d\n", countNum);
        result = countNum + result;
        countNum = 0;
    }
   
    printf("%lf\n", result);
   
    free(re);

    return 0;
}