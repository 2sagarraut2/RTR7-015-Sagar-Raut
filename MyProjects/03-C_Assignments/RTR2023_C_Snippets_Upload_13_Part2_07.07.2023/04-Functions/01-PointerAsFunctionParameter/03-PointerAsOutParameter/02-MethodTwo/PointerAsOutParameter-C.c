#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    void MathematicalOprations(int, int, int *, int *, int *, int *, int *);

    int a = 0, b = 0;
    int *sumResult = NULL;
    int *differenceResult = NULL;
    int *productResult = NULL;
    int *quotientResult = NULL;
    int *remainderResult = NULL;

    printf("\n\n");
    printf("Enter first number\n");
    scanf("%d", &a);

    printf("\n");
    printf("Enter second number\n");
    scanf("%d", &b);
    printf("\n");

    sumResult = (int *)malloc(1 * sizeof(int));
    if (sumResult == NULL)
    {
        printf("Could not allocate memory for 'sumResult', exiting now!\n");
        exit(0);
    }

    differenceResult = (int *)malloc(1 * sizeof(int));
    if (differenceResult == NULL)
    {
        printf("Could not allocate memory for 'differenceResult', exiting now!\n");
        exit(0);
    }

    productResult = (int *)malloc(1 * sizeof(int));
    if (productResult == NULL)
    {
        printf("Could not allocate memory for 'productResult', exiting now!\n");
        exit(0);
    }

    quotientResult = (int *)malloc(1 * sizeof(int));
    if (quotientResult == NULL)
    {
        printf("Could not allocate memory for 'quotientResult', exiting now!\n");
        exit(0);
    }

    remainderResult = (int *)malloc(1 * sizeof(int));
    if (remainderResult == NULL)
    {
        printf("Could not allocate memory for 'remainderResult', exiting now!\n");
        exit(0);
    }

    MathematicalOprations(a, b, sumResult, differenceResult, productResult, quotientResult, remainderResult);

    printf("Result of calculations\n");
    printf("Result of Sum = %d\n", *sumResult);
    printf("Result of difference = %d\n", *differenceResult);
    printf("Result of product = %d\n", *productResult);
    printf("Result of division = %d\n", *quotientResult);
    printf("Result of mod operation = %d\n", *remainderResult);
    printf("\n");

    if (sumResult)
    {
        free(sumResult);
        printf("Memory allocated for 'sumResult' has been released!\n");
    }
    if (differenceResult)
    {
        free(differenceResult);
        printf("Memory allocated for 'differenceResult' has been released!\n");
    }
    if (productResult)
    {
        free(productResult);
        printf("Memory allocated for 'productResult' has been released!\n");
    }
    if (quotientResult)
    {
        free(quotientResult);
        printf("Memory allocated for 'quotientResult' has been released!\n");
    }
    if (remainderResult)
    {
        free(remainderResult);
        printf("Memory allocated for 'remainderResult' has been released!\n");
    }

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