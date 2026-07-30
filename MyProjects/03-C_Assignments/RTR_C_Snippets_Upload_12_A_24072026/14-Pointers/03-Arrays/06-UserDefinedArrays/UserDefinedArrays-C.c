#include <stdio.h>
#include <stdlib.h>

#define INT_SIZE sizeof(int)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)
#define CHAR_SIZE sizeof(char)

int main(void)
{
    int *ptriArray = NULL;
    unsigned int intArrayLength = 0;

    float *ptrffArray = NULL;
    unsigned int floatArrayLength = 0;

    double *ptrdArray = NULL;
    unsigned int doubelArrayLength = 0;

    char *ptrcArray = NULL;
    unsigned int charArrayLength = 0;

    int i;

    printf("\n\n");
    printf("ENter the number of elements you want in the integer array\n");
    scanf("%u", &intArrayLength);

    ptriArray = (int *)malloc(INT_SIZE * intArrayLength);

    if (ptriArray == NULL)
    {
        printf("\n\n");
        printf("Memory allocation for integer array has failed. Exiting now!\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("Memory has been allocated for integer array\n");
    }

    printf("\n\n");
    printf("Enter the %d integer elements to fill up integer array\n", intArrayLength);
    for (i = 0; i < intArrayLength; i++)
    {
        scanf("%d", (ptriArray + i));
    }

    printf("\n\n");
    printf("ENter the number of elements you want in the float array\n");
    scanf("%u", &floatArrayLength);

    ptrffArray = (float *)malloc(FLOAT_SIZE * floatArrayLength);

    if (ptrffArray == NULL)
    {
        printf("\n\n");
        printf("Memory allocation for float array has failed. Exiting now!\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("Memory has been allocated for float array\n");
    }

    printf("\n\n");
    printf("Enter the %d float elements to fill up float array\n", floatArrayLength);
    for (i = 0; i < floatArrayLength; i++)
    {
        scanf("%f", (ptrffArray + i));
    }

    printf("\n\n");
    printf("Enter the number of elements you want in the double array\n");
    scanf("%u", &doubelArrayLength);

    ptrdArray = (double *)malloc(DOUBLE_SIZE * doubelArrayLength);

    if (ptrdArray == NULL)
    {
        printf("\n\n");
        printf("Memory allocation for double array has failed. Exiting now!\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("Memory has been allocated for double array\n");
    }

    printf("\n\n");
    printf("Enter the %d double elements to fill up double array\n", doubelArrayLength);
    for (i = 0; i < doubelArrayLength; i++)
    {
        scanf("%lf", (ptrdArray + i));
    }

    printf("\n\n");
    printf("Enter the number of elements you want in the char array\n");
    scanf("%u", &charArrayLength);

    ptrcArray = (char *)malloc(CHAR_SIZE * charArrayLength);

    if (ptrcArray == NULL)
    {
        printf("\n\n");
        printf("Memory allocation for char array has failed. Exiting now!\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("Memory has been allocated for char array\n");
    }

    printf("\n\n");
    printf("Enter the %d char elements to fill up char array\n", charArrayLength);
    for (i = 0; i < charArrayLength; i++)
    {
        scanf(" %c", (ptrcArray + i));
    }

    // integer array
    printf("\n\n");
    printf("The integer array consists of %d elements as follows:\n", intArrayLength);

    for (i = 0; i < intArrayLength; i++)
    {
        printf("%d \t \t at address: %p\n", *(ptriArray + i), (ptriArray + i));
    }

    // float array
    printf("\n\n");
    printf("The float array consists of %d elements as follows:\n", floatArrayLength);

    for (i = 0; i < floatArrayLength; i++)
    {
        printf("%f \t \t at address: %p\n", *(ptrffArray + i), (ptrffArray + i));
    }

    // double array
    printf("\n\n");
    printf("The double array consists of %d elements as follows:\n", doubelArrayLength);

    for (i = 0; i < doubelArrayLength; i++)
    {
        printf("%lf \t \t at address: %p\n", *(ptrdArray + i), (ptrdArray + i));
    }

    // char array
    printf("\n\n");
    printf("The char array consists of %d elements as follows:\n", charArrayLength);

    for (i = 0; i < charArrayLength; i++)
    {
        printf("%c \t \t at address: %p\n", *(ptrcArray + i), (ptrcArray + i));
    }

    printf("\n\n--End--\n\n");
    return (0);
}