#include <stdio.h>

int main(void)
{

    int SR_i, SR_j;

    SR_i = 1;
    while (SR_i <= 10)
    {
        printf("SR_i = %d\n", SR_i);

        printf("-----------\n");

        SR_j = 1;
        while (SR_j <= 5)
        {
            printf("\tj = %d\n", SR_j);
            SR_j++;
        }
        SR_i++;
        printf("\n\n");
    }

    return 0;
}