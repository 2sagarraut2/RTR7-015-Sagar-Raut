#include <stdio.h>

#define MAX_NUMBER(a, b) ((a > b) ? a : b)

int main(int argc, char *argv[], char *envp[])
{

    int SR_iNum_01, SR_iNum_02, SR_iResult;

    float fNum_01, SR_fNum_02, SR_fResult;

    printf("\n\n");
    printf("Enter a number\n");
    scanf("%d", &SR_iNum_01);

    printf("\n\n");
    printf("Enter a number\n");
    scanf("%d", &SR_iNum_02);

    SR_iResult = MAX_NUMBER(SR_iNum_01, SR_iNum_02);

    printf("SR_result of macro function MAX_NUMBER() = %d", SR_iResult);

    printf("\n\n");

    printf("Enter a float number\n");
    scanf("%f", &fNum_01);

    printf("Enter a float number\n");
    scanf("%f", &SR_fNum_02);

    SR_fResult = MAX_NUMBER(fNum_01, SR_fNum_02);

    printf("SR_result of macro function MAX_NUMBER() = %f", SR_fResult);

    printf("\n---End---\n");

    return (0);
}