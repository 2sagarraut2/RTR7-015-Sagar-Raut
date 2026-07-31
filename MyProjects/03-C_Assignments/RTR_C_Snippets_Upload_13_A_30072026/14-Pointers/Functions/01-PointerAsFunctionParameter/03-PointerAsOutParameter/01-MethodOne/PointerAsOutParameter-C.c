#include <stdio.h>

int main(void)
{
    void mathematicalOperations(int, int, int *, int *, int *, int *, int *);

    int a = 0, b = 0;
    int ansSum = 0;
    int ansSub = 0;
    int ansMult = 0;
    int ansDivQuo = 0;
    int ansDivRem = 0;

    printf("Please enter one number\n");
    scanf("%d", &a);

    printf("Please enter second number\n");
    scanf("%d", &b);

    mathematicalOperations(a, b, &ansSum, &ansSub, &ansMult, &ansDivQuo, &ansDivRem);

    printf("Results\n\n");
    printf("Sum = %d\n", ansSum);
    printf("Substraction = %d\n", ansSub);
    printf("Multiplecation = %d\n", ansMult);
    printf("Quotient = %d\n", ansDivQuo);
    printf("Remainder = %d\n", ansDivRem);

    printf("\n\n--End--\n\n");
    return (0);
}

void mathematicalOperations(int a, int b, int *ansSum, int *ansSub, int *ansMult, int *ansDivQuo, int *ansDiveRem)
{
    *ansSum = a + b;
    *ansSub = a - b;
    *ansMult = a * b;
    *ansDivQuo = a / b;
    *ansDiveRem = a % b;
}