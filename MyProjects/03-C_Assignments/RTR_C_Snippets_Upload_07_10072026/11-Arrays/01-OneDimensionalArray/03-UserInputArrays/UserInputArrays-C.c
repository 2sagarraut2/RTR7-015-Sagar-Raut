#include <stdio.h>

#define SR_INT_ARRAY_NUM_ELEMENTS 5
#define SR_FLOAT_ARRAY_NUM_ELEMENTS 3
#define SR_CHAR_ARRAY_NUM_ELEMENTS 15

int main(void)
{
    int SR_iArray[SR_INT_ARRAY_NUM_ELEMENTS];
    float SR_fArray[SR_FLOAT_ARRAY_NUM_ELEMENTS];
    char SR_cArray[SR_CHAR_ARRAY_NUM_ELEMENTS];
    int i, SR_num;

    printf("\n\n");
    printf("Enter elements for Integer array: \n");
    for (i = 0; i < SR_INT_ARRAY_NUM_ELEMENTS; i++)
    {
        scanf("%d", &SR_iArray[i]);
    }

    printf("\n\n");
    printf("Enter elements for floating-point array: \n");
    for (i = 0; i < SR_FLOAT_ARRAY_NUM_ELEMENTS; i++)
    {
        scanf("%f", &SR_fArray[i]);
    }

    printf("\n\n");
    printf("Enter elements for character array: \n");
    for (i = 0; i < SR_CHAR_ARRAY_NUM_ELEMENTS; i++)
    {
        scanf(" %c", &SR_cArray[i]);
        printf("%c\n", SR_cArray[i]);
    }

    printf("\n\n");
    printf("Integer array entered by you: \n\n");
    for (i = 0; i < SR_INT_ARRAY_NUM_ELEMENTS; i++)
    {
        printf("%d\n", SR_iArray[i]);
    }

    printf("\n\n");
    printf("Floating-point array entered by you: \n\n");
    for (i = 0; i < SR_FLOAT_ARRAY_NUM_ELEMENTS; i++)
    {
        printf("%f\n", SR_fArray[i]);
    }

    printf("\n\n");
    printf("Character array entered by you: \n\n");
    for (i = 0; i < SR_CHAR_ARRAY_NUM_ELEMENTS; i++)
    {
        printf("%c\n", SR_cArray[i]);
    }

    printf("\n\n--End--\n\n");
    return (0);
}