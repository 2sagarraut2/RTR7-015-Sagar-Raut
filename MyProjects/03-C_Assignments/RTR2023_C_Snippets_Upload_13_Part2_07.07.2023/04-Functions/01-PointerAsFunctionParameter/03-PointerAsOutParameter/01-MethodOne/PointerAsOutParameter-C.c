#include <stdio.h>

int main(void)
{
    void MathematicalOprations(int, int, int *, int *, int *, int *, int *);

    int a = 0, b = 0;
    int sumResult = 0, differenceResult = 0, productResult = 0, quotientResult = 0, remainderResult = 0;

    printf("\n\n");
    printf("Enter first number\n");
    scanf("%d", &a);

    printf("\n");
    printf("Enter second number\n");
    scanf("%d", &b);

    MathematicalOprations(a, b, &sumResult, &differenceResult, &productResult, &quotientResult, &remainderResult);

    printf("Result of calculations\n");
    printf("Result of Sum = %d\n", sumResult);
    printf("Result of difference = %d\n", differenceResult);
    printf("Result of product = %d\n", productResult);
    printf("Result of division = %d\n", quotientResult);
    printf("Result of mod operation = %d\n", remainderResult);

    printf("\n\n--End--\n\n");
    return (0);
}

void MathematicalOprations(int var1, int var2, int *sum, int *difference, int *product, int *quotient, int *remainder)
{
    *sum = var1 + var2;
    *difference = var1 - var2;
    *product = var1 * var2;
    *quotient = var1 / var2;
    *remainder = var1 % var2;
}