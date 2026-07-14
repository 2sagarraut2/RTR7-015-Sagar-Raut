#include <stdio.h>

#define SR_NUM_ELEMENTS 10

int main(void)
{
    int SR_iArray[SR_NUM_ELEMENTS];
    int i, SR_sum = 0;

    printf("Enter numbers for array\n");
    for (i = 0; i < SR_NUM_ELEMENTS; i++)
    {
        scanf("%d", &SR_iArray[i]);
    }

    for (i = 0; i < SR_NUM_ELEMENTS; i++)
    {
        SR_sum = SR_sum + SR_iArray[i];
    }

    printf("Sum of all elements of array: %d\n", SR_sum);

    printf("\n\n--End--\n\n");
    return (0);
}