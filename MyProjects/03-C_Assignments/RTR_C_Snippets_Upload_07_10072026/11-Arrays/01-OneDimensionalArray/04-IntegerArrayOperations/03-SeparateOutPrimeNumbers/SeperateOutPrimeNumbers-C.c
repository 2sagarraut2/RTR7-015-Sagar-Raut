#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
    int iArray[NUM_ELEMENTS];
    int i, num, j, count = 0;

    printf("\n\n");

    printf("Enter integer elements for Array\n\n");
    for (i = 0; i < NUM_ELEMENTS; i++)
    {
        scanf("%d", &num);

        if (num < 0)
        {
            num = -1 * num;
        }

        iArray[i] = num;
    }

    printf("\n\n");
    printf("Array elements are:\n\n");
    for (i = 0; i < NUM_ELEMENTS; i++)
    {
        printf("%d", iArray[i]);
    }

    printf("\n\n");
    printf("Prime number amongst array\n\n");
    for (i = 0; i < NUM_ELEMENTS; i++)
    {
        for (j = 0; j <= iArray[i]; j++)
        {
            if ((iArray[i] % j) == 0)
            {
                count++;
            }
        }

        if (count == 2)
        {
            printf("%d\n", iArray[i]);
        }

        count = 0;
    }

    printf("\n\n--End--\n\n");
    return (0);
}