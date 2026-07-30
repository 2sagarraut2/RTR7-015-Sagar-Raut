#include <stdio.h>

int main(void)
{
    int SR_iArray[10];
    int SR_i;

    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        SR_iArray[SR_i] = (SR_i + 1) * 2;
    }

    printf("\n\n");
    printf("Elements of the integer array :\n\n");
    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        printf("SR_iArray[%d] = %d\n", SR_i, SR_iArray[SR_i]);
    }

    printf("\n\n");
    printf("Elements of the integer array and their addresses:\n\n");
    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        printf("SR_iArray[%d] = %d \t \t is at address %p\n", SR_i, SR_iArray[SR_i], &SR_iArray[SR_i]);
    }

    printf("\n\n--End--\n\n");
    return (0);
}