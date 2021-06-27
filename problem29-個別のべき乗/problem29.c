#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A_MAX  5
#define A_MIN  2

#define B_MAX  5
#define B_MIN  2

//指数を単純化する関数
int canSimplification(double a, double b)
{
    double dResult;
    int count = 2;
    double exp;
    int iResult;

    while(dResult > 2){
        exp = 1.0 / count;
        dResult = pow(a, exp);
        iResult = dResult;
        count++;
        if(iResult == dResult) return iResult + b;
    }
    return 0;
}

int main(void)
{
    double a = 8.0;
    double b = 2;

    printf("a = %lf\n", a);
    printf("b = %lf\n", b);
    printf("result = %d", canSimplification(a, b));
    
    /*for(int b = B_MIN ; b < B_MAX + 1 ; b++){
        for(int a = A_MIN ; a < A_MAX + 1 ; a++){
            re = canSimplification(a, b);
           
            if(re[0] != -1){
                if(re[0] > A_MIN && re[0] < A_MAX + 1 && re[1] > B_MIN && re[1] < B_MAX + 1) countNum++;
            }
        }
    }*/

    return 0;
}