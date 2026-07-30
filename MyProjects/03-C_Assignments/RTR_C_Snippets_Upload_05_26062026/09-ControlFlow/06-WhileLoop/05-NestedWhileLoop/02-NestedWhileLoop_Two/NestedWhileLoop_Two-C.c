#include <stdio.h>

int main(void)
{

    int SR_i, SR_j, SR_k;

    SR_i = 1;
    while (SR_i <= 10)
    {
        printf("SR_i = %d\n", SR_i);

        printf("-----------\n\n");

        SR_j = 1;
        while (SR_j <= 5)
        {
            printf("\tj = %d\n", SR_j);

            printf("\t-----------\n\n");

            SR_k = 1;
            while (SR_k <= 3)
            {
                printf("\t\tk = %d \n", SR_k);
                SR_k++;
            }

            printf("\n\n");
            SR_j++;
        }
        SR_i++;
        printf("\n\n");
    }

    return 0;
}