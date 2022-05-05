#include <stdio.h>
#include <stdlib.h>

#define PAND_SIZE 9

int fact(int fNum){
    if(fNum != 1){
        return fNum * fact(fNum - 1);
    }else{
        return 1;
    }
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

int getLeftValue(int num, int leftNum)
{
    int num1, num2;
    int moveDecimalPointNum = 1;

    if(num < 1 || leftNum < 1) return -1;
    for(int i = 0 ; i < getDigitNum(num) - leftNum ; i++){
        moveDecimalPointNum = moveDecimalPointNum * 10;
    }
    num1 = num / moveDecimalPointNum;
    if(num1 == 0 && num2 == 0) return -1;

    return num1;
}

int getRightValue(int num, int leftValue, int leftNum)
{
    int moveDecimalPointNum = 1;

    for(int i = 0 ; i < getDigitNum(num) - leftNum ; i++){
        moveDecimalPointNum = moveDecimalPointNum * 10;
    }
    return num - leftValue * moveDecimalPointNum;
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



//順列生成関数 Pn =（数列, n）
void makePermutation(int seq, int maxDigitNum, FILE *fp)
{
    int replaceNum = getDigitNum(seq);

    if(replaceNum == maxDigitNum) return;
    seq = seq * 10 + (replaceNum + 1);
    for(int i = 0 ; i < replaceNum + 1 ; i++){
        makePermutation(seq, maxDigitNum, fp);
        if(replaceNum + 1 == maxDigitNum) fprintf(fp, "%d\n", seq);
        seq = swapLeft(seq, i + 1);
    }
}

//ファイルオープン関数
FILE *openFile(char *openFileName, char *mode)
{
    FILE *fp;
    fp = fopen(openFileName, mode);

    if(fp == NULL){
        printf("-----------Output failure-----------");
        exit(1);
    }
    return fp;
}

//main
int main(void)
{
    int mulMin1 = 1, mulMin2 = 1;
    int mulMax1, mulMax2;
    int pandLengthMin = 1, pandLengthMax = 1;
    int mulDigit[PAND_SIZE][2];
    int mulCase = 0, mulCaseNum = 0;
    int mulComMax;

    for(int j = 1 ; j < PAND_SIZE ; j++){
        for(int i = 1 ; i < PAND_SIZE ; i++){
            if(i <= j){
                mulMax1 = mulMin1 * 9;
                mulMax2 = mulMin2 * 9;
                pandLengthMin = i + j + getDigitNum(mulMin1 * mulMin2);
                pandLengthMax = i + j + getDigitNum(mulMax1 * mulMax2);
               
                if(pandLengthMin == PAND_SIZE - 1 || pandLengthMin == PAND_SIZE){
                    //printf("%d桁、%d桁\n", i, j);
                    mulDigit[mulCaseNum][mulCase] = i;
                    mulCase++;
                    mulDigit[mulCaseNum][mulCase] = j;
                    mulCase = 0;
                    mulCaseNum++;
                    mulComMax = mulCaseNum;
                }
                mulMin1 = mulMin1 * 10 + 1;
            }
        }
        mulMin1 = 1;
        mulMin2 = mulMin2 * 10 + 1;
        pandLengthMax = 1;
   }

   //printf("%d\n", getLeftValue(123456789, 3));
   //printf("%d\n", getRightValue(123456789, getLeftValue(123456789, 3), 3));
   

    FILE *permFp;
    FILE *resultFp;
    
    char openFileName[] = "permutations.txt";
    char resultFileName[] = "result.txt";
    int permNum, mul1, mul2, answer;
    int result, resultNum = 0, resultSum = 0;

    permFp = openFile(openFileName, "w");
    makePermutation(1, PAND_SIZE, permFp);
    fclose(permFp);

    permFp = openFile(openFileName, "r");
    resultFp = openFile(resultFileName, "w");

    while(fscanf(permFp, "%d", &permNum) != EOF) {
		//permNumを分解して積の式に変換し積が一致するか判定

        for(int i = 0 ; i < mulComMax ; i++){
            //printf("%d桁、%d桁\n", mulDigit[i][0], mulDigit[i][1]);
            mul1 = getLeftValue(permNum, mulDigit[i][0]);
            answer = getRightValue(permNum, mul1, mulDigit[i][0]);
            mul2 = getLeftValue(answer, mulDigit[i][1]);
            answer = getRightValue(answer, mul2, mulDigit[i][1]);

            if(mul1 * mul2 == answer){
                fprintf(resultFp, "%d\n", answer);
                resultNum++;
            }
        }
        //printf("%d\n", permNum);
	}
    fclose(permFp);
    fclose(resultFp);

    int resultArray[resultNum];
    int count = 0;

    resultFp = openFile(resultFileName, "r");

    while(fscanf(resultFp, "%d", &result) != EOF) {
        resultArray[count] = result;
        count++;
    }

    fclose(resultFp);

    for(int i = 0 ; i < resultNum ; i++){
        for(int j = 0 ; j < resultNum ; j++){
            if(i != j && resultArray[i] == resultArray[j]){
                resultArray[i] = 0;
                j = resultNum;
            }
        }
    }

    for(int i = 0 ; i < resultNum ; i++){
        resultSum = resultArray[i] + resultSum;
    }

    printf("resultSum = %d\n", resultSum);

    return 0;
}