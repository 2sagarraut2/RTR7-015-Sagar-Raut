#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
    int iArray[NUM_ELEMENTS];
    int i, sum = 0;

    printf("Enter numbers for array\n");
    for (i = 0; i < NUM_ELEMENTS; i++)
    {
        scanf("%d", &iArray[i]);
    }

    for (i = 0; i < NUM_ELEMENTS; i++)
    {
        sum = sum + iArray[i];
    }

    printf("Sum of all elements of array: %d\n", sum);

    printf("\n\n--End--\n\n");
    return (0);
}