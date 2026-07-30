#include <stdio.h>

#define SR_INT_ARRAY_NUM_ELEMENTS 5
#define SR_FLOAT_ARRAY_NUM_ELEMENTS 3
#define SR_CHAR_ARRAY_NUM_ELEMENTS 15

int main(void)
{
    int SR_iArray[SR_INT_ARRAY_NUM_ELEMENTS];
    float SR_fArray[SR_FLOAT_ARRAY_NUM_ELEMENTS];
    char SR_cArray[SR_CHAR_ARRAY_NUM_ELEMENTS];
    int SR_i, SR_num;

    printf("\n\n");
    printf("Enter elements for Integer array: \n");
    for (SR_i = 0; SR_i < SR_INT_ARRAY_NUM_ELEMENTS; SR_i++)
    {
        scanf("%d", &SR_iArray[SR_i]);
    }

    printf("\n\n");
    printf("Enter elements for floating-point array: \n");
    for (SR_i = 0; SR_i < SR_FLOAT_ARRAY_NUM_ELEMENTS; SR_i++)
    {
        scanf("%f", &SR_fArray[SR_i]);
    }

    printf("\n\n");
    printf("Enter elements for character array: \n");
    for (SR_i = 0; SR_i < SR_CHAR_ARRAY_NUM_ELEMENTS; SR_i++)
    {
        scanf(" %c", &SR_cArray[SR_i]);
        printf("%c\n", SR_cArray[SR_i]);
    }

    printf("\n\n");
    printf("Integer array entered by you: \n\n");
    for (SR_i = 0; SR_i < SR_INT_ARRAY_NUM_ELEMENTS; SR_i++)
    {
        printf("%d\n", SR_iArray[SR_i]);
    }

    printf("\n\n");
    printf("Floating-point array entered by you: \n\n");
    for (SR_i = 0; SR_i < SR_FLOAT_ARRAY_NUM_ELEMENTS; SR_i++)
    {
        printf("%f\n", SR_fArray[SR_i]);
    }

    printf("\n\n");
    printf("Character array entered by you: \n\n");
    for (SR_i = 0; SR_i < SR_CHAR_ARRAY_NUM_ELEMENTS; SR_i++)
    {
        printf("%c\n", SR_cArray[SR_i]);
    }

    printf("\n\n--End--\n\n");
    return (0);
}