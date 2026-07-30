#include <stdio.h>

int main(void)
{

    int SR_i, SR_j, k;

    for (SR_i = 1; SR_i <= 10; SR_i++)
    {
        printf("\ti = %d\n", SR_i);
        for (SR_j = 1; SR_j <= 5; SR_j++)
        {
            printf("\t\tj = %d\n", SR_j);
            for (k = 1; k <= 5; k++)
            {
                printf("\t\t\tk = %d\n", k);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}