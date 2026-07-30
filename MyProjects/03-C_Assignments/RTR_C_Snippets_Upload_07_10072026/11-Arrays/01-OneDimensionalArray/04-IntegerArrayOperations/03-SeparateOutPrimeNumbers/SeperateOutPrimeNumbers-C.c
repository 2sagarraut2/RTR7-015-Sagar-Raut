#include <stdio.h>

#define SR_NUM_ELEMENTS 10

int main(void)
{
    int SR_iArray[SR_NUM_ELEMENTS];
    int SR_i, SR_num, SR_j, SR_count = 0;

    printf("\n\n");

    printf("Enter integer elements for Array\n\n");
    for (SR_i = 0; SR_i < SR_NUM_ELEMENTS; SR_i++)
    {
        scanf("%d", &SR_num);

        if (SR_num < 0)
        {
            SR_num = -1 * SR_num;
        }

        SR_iArray[SR_i] = SR_num;
    }

    printf("\n\n");
    printf("Array elements are:\n\n");
    for (SR_i = 0; SR_i < SR_NUM_ELEMENTS; SR_i++)
    {
        printf("%d", SR_iArray[SR_i]);
    }

    printf("\n\n");
    printf("Prime number amongst array\n\n");
    for (SR_i = 0; SR_i < SR_NUM_ELEMENTS; SR_i++)
    {
        for (SR_j = 0; SR_j <= SR_iArray[SR_i]; SR_j++)
        {
            if ((SR_iArray[SR_i] % SR_j) == 0)
            {
                SR_count++;
            }
        }

        if (SR_count == 2)
        {
            printf("%d\n", SR_iArray[SR_i]);
        }

        SR_count = 0;
    }

    printf("\n\n--End--\n\n");
    return (0);
}