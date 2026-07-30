#include <stdio.h>

int main(void)
{

    int SR_i, SR_j;

    for (SR_i = 1; SR_i <= 10; SR_i++)
    {

        printf("\ti = %d\n", SR_i);
        for (SR_j = 1; SR_j <= 10; SR_j++)
        {

            printf("\tj = %d\n", SR_j);
        }
        printf("\n");
    }

    return 0;
}