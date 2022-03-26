#include <stdio.h>

int fact(int fNum){
    if(fNum != 1){
        return fNum * fact(fNum - 1);
    }else{
        return 1;
    }
}

//指定した桁の値を取得する関数
int getDigitValue(int num, int digit)
{
    int num1, num2;
    int moveDecimalPointNum = 1;

    if(num < 1 || digit < 1) return -1;

    for(int i = 0 ; i < digit - 1 ; i++){
        moveDecimalPointNum = moveDecimalPointNum * 10;
    }

    num1 = num / moveDecimalPointNum;
    num2 = (num / (moveDecimalPointNum * 10)) * 10;

    if(num1 == 0 && num2 == 0) return -1;

    return num1 - num2;
}

//指定した桁とその左隣の桁数を入れ替える関数
int swapLeft(int num, int swapDigit)
{
    int radix, result;
    int moveDecimalPointNum = 1;

    for(int i = 0 ; i < swapDigit ; i++){
        moveDecimalPointNum = moveDecimalPointNum * 10;
    }

    radix = getDigitValue(num, swapDigit) - getDigitValue(num, swapDigit + 1);
    result = num + radix * moveDecimalPointNum - radix * (moveDecimalPointNum / 10);

    return result;
}

//桁数取得関数
int getDigitNum(int num)
{
    int result = 0;
    int moveDecimalPointNum = 1;

    while(num / moveDecimalPointNum >= 1){
        result++;
        moveDecimalPointNum = moveDecimalPointNum * 10;
    }
    return result;
}

//順列生成関数 Pn =（数列, n）
void makePermutation(int seq, int maxDigitNum)
{
    int replaceNum = getDigitNum(seq);

    if(replaceNum == maxDigitNum) return;

    seq = seq * 10 + (replaceNum + 1);
    makePermutation(seq, maxDigitNum);
    if(replaceNum + 1 == maxDigitNum) printf("return = %d\n", seq);

    for(int i = 0 ; i < replaceNum ; i++){
        seq = swapLeft(seq, i + 1);
        makePermutation(seq, maxDigitNum);
        if(replaceNum + 1 == maxDigitNum) printf("return = %d\n", seq);
    }
}

//main
int main(void)
{
    makePermutation(1, 9);

    return 0;
}