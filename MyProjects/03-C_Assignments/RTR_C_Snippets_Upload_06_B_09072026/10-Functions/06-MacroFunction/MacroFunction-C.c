#include <stdio.h>

#define MAX_NUMBER(a, b) ((a > b) ? a : b)

int main(int argc, char *argv[], char *envp[])
{

    int iNum_01, iNum_02, iResult;

    float fNum_01, fNum_02, fResult;

    printf("\n\n");
    printf("Enter a number\n");
    scanf("%d", &iNum_01);

    printf("\n\n");
    printf("Enter a number\n");
    scanf("%d", &iNum_02);

    iResult = MAX_NUMBER(iNum_01, iNum_02);

    printf("result of macro function MAX_NUMBER() = %d", iResult);

    printf("\n\n");

    printf("Enter a float number\n");
    scanf("%f", &fNum_01);

    printf("Enter a float number\n");
    scanf("%f", &fNum_02);

    fResult = MAX_NUMBER(fNum_01, fNum_02);

    printf("result of macro function MAX_NUMBER() = %f", fResult);

    printf("\n---End---\n");

    return (0);
}