#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A_MAX  5
#define A_MIN  2

#define B_MAX  5
#define B_MIN  2

//指数を単純化する関数
double *canSimplification(double a, double b)
{
    double* re = NULL;
    re = (double*)malloc(sizeof(double) * 2);

    double* re2 = NULL;
    double dResult;
    int count = 2;
    double exp;
    int iResult;

    re[0] = -1;
    re[1] = -1;

    while(dResult > 2){
        exp = 1.0 / count;
        dResult = pow(a, exp);
        iResult = dResult;
        if(iResult == dResult){
            re[0] = iResult;
            re[1] = count * b;
            re2 = canSimplification(re[0], re[1]);

            if(re2[0] == -1) return re;
        }
        count++;
    }
    return re;
}

int main(void)
{
    double a = 16.0;
    double b = 2;
    double* re = NULL;

    printf("(%lf, %lf)\n", a, b);
    re = canSimplification(a, b);
    printf("(%lf, %lf)\n", re[0], re[1]);
    
    /*for(int b = B_MIN ; b < B_MAX + 1 ; b++){
        for(int a = A_MIN ; a < A_MAX + 1 ; a++){
            re = canSimplification(a, b);
           
            if(re[0] != -1){
                if(re[0] > A_MIN && re[0] < A_MAX + 1 && re[1] > B_MIN && re[1] < B_MAX + 1) countNum++;
            }
        }
    }*/

    free(re);

    return 0;
}