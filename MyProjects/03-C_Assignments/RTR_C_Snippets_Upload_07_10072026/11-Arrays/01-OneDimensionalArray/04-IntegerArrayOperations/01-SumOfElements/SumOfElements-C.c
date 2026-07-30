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

    printf("Sum of all elements of array: %d\n", SR_sum);

    printf("\n\n--End--\n\n");
    return (0);
}