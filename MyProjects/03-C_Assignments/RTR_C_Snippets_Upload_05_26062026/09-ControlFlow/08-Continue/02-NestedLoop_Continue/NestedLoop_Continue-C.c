#include <stdio.h>

int main(void)
{

    int SR_i, SR_j;

    printf("\n");

    printf("Outer loop prints odd numbers from 1 to 10\n");
    printf("Inner loop prints even numbers from 1 to 10 for every odd number printed by outer loop\n");

    for (SR_i = 0; SR_i <= 10; SR_i++)
    {
        if (SR_i % 2 != 0)
        {
            printf("SR_i = %d\n", SR_i);
            printf("--------------\n");

            for (SR_j = 1; SR_j <= 10; SR_j++)
            {
                if (SR_j % 2 == 0)
                {
                    printf("\t SR_j = %d\n", SR_j);
                }
                else
                {
                    continue;
                }
            }
            printf("\n\n");
        }
        else
        {
            continue;
        }
    }

    printf("\n\n");

    return 0;
}