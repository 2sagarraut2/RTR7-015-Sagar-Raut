#include <stdio.h>

int main(void)
{
    float SR_fArray[10];
    int SR_i;

    printf("\n\n");

    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        SR_fArray[SR_i] = (float)(SR_i + 1) * 2.5f;
    }

    printf("elements of float array:");
    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        printf("SR_fArray[%d] = %f\n", SR_i, SR_fArray[SR_i]);
    }

    printf("\n\n");

    printf("elements and addresses of float array:\n\n");
    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        printf("SR_fArray[%d] = %f \t \t address = %p\n", SR_i, SR_fArray[SR_i], &SR_fArray[SR_i]);
    }

    printf("\n\n--End--\n\n");
    return (0);
}