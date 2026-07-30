#include <stdio.h>

int main(void)
{

    int SR_i, SR_j;

    printf("\n");

    SR_i = 1;
    do
    {
        printf("SR_i = %d \n", SR_i);
        printf("------------");

        SR_j = 1;
        do
        {
            printf("\t SR_j = %d\n", SR_j);
            SR_j++;
        } while (SR_j <= 5);

        SR_i++;
        printf("\n\n");

    } while (SR_i <= 10);

    return 0;
}