#include <stdio.h>

#define SR_NUM_ELEMENTS 10

int main(void)
{
    int SR_iArray[SR_NUM_ELEMENTS];
    int i, SR_num, j, SR_count = 0;

    printf("\n\n");

    printf("Enter integer elements for Array\n\n");
    for (i = 0; i < SR_NUM_ELEMENTS; i++)
    {
        scanf("%d", &SR_num);

        if (SR_num < 0)
        {
            SR_num = -1 * SR_num;
        }

        SR_iArray[i] = SR_num;
    }

    printf("\n\n");
    printf("Array elements are:\n\n");
    for (i = 0; i < SR_NUM_ELEMENTS; i++)
    {
        printf("%d", SR_iArray[i]);
    }

    printf("\n\n");
    printf("Prime number amongst array\n\n");
    for (i = 0; i < SR_NUM_ELEMENTS; i++)
    {
        for (j = 0; j <= SR_iArray[i]; j++)
        {
            if ((SR_iArray[i] % j) == 0)
            {
                SR_count++;
            }
        }

        if (SR_count == 2)
        {
            printf("%d\n", SR_iArray[i]);
        }

        SR_count = 0;
    }

    printf("\n\n--End--\n\n");
    return (0);
}