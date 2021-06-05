#include <stdio.h>

int main(void)
{
    long long int result = 1;
    long long int diagonalNum = 1;
    long long int addNum = 2;
    long long int count = 2;

    while (addNum < 1001)
    {
        for(long long int i = 0 ; i < 4 ; i++){
            diagonalNum = diagonalNum + addNum;
            result = result + diagonalNum;
        }
        addNum = addNum + 2;
    }

    printf("%lld\n", result);

    return 0;
}