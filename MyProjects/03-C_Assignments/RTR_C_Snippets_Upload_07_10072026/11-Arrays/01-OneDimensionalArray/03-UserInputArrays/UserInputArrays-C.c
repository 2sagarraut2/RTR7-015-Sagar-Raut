#include <stdio.h>

#define INT_ARRAY_NUM_ELEMENTS 5
#define FLOAT_ARRAY_NUM_ELEMENTS 3
#define CHAR_ARRAY_NUM_ELEMENTS 15

int main(void)
{
    int iArray[INT_ARRAY_NUM_ELEMENTS];
    float fArray[FLOAT_ARRAY_NUM_ELEMENTS];
    char cArray[CHAR_ARRAY_NUM_ELEMENTS];
    int i, num;

    printf("\n\n");
    printf("Enter elements for Integer array: \n");
    for (i = 0; i < INT_ARRAY_NUM_ELEMENTS; i++)
    {
        scanf("%d", &iArray[i]);
    }

    printf("\n\n");
    printf("Enter elements for floating-point array: \n");
    for (i = 0; i < FLOAT_ARRAY_NUM_ELEMENTS; i++)
    {
        scanf("%f", &fArray[i]);
    }

    printf("\n\n");
    printf("Enter elements for character array: \n");
    for (i = 0; i < CHAR_ARRAY_NUM_ELEMENTS; i++)
    {
        scanf(" %c", &cArray[i]);
        printf("%c\n", cArray[i]);
    }

    printf("\n\n");
    printf("Integer array entered by you: \n\n");
    for (i = 0; i < INT_ARRAY_NUM_ELEMENTS; i++)
    {
        printf("%d\n", iArray[i]);
    }

    printf("\n\n");
    printf("Floating-point array entered by you: \n\n");
    for (i = 0; i < FLOAT_ARRAY_NUM_ELEMENTS; i++)
    {
        printf("%f\n", fArray[i]);
    }

    printf("\n\n");
    printf("Character array entered by you: \n\n");
    for (i = 0; i < CHAR_ARRAY_NUM_ELEMENTS; i++)
    {
        printf("%c\n", cArray[i]);
    }

    printf("\n\n--End--\n\n");
    return (0);
}