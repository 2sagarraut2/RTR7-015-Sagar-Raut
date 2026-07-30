#include <stdio.h>

#define SR_NUM_ELEMENTS 10

int main(void)
{
    int SR_iArray[SR_NUM_ELEMENTS];
    int SR_i, SR_sum = 0;

    printf("Enter numbers for array\n");
    for (SR_i = 0; SR_i < SR_NUM_ELEMENTS; SR_i++)
    {
        scanf("%d", &SR_iArray[SR_i]);
    }

    for (SR_i = 0; SR_i < SR_NUM_ELEMENTS; SR_i++)
    {
        SR_sum = SR_sum + SR_iArray[SR_i];
    }

    printf("\n\n");
    printf("Even numbers amonst the array\n\n");

    for (SR_i = 0; SR_i < SR_NUM_ELEMENTS; SR_i++)
    {
        if (SR_iArray[SR_i] % 2 == 0)
        {
            printf("%d\n", SR_iArray[SR_i]);
        }
    }

    printf("\n\n");
    printf("Odd numbers amonst the array\n\n");
    for (SR_i = 0; SR_i < SR_NUM_ELEMENTS; SR_i++)
    {
        if (SR_iArray[SR_i] % 2 != 0)
        {
            printf("%d\n", SR_iArray[SR_i]);
        }
    }

    printf("\n\n--End--\n\n");
    return (0);
}