#include <stdio.h>

int main(void)
{

    int i, j;

    printf("\n");

    printf("Outer loop prints odd numbers from 1 to 10\n");
    printf("Inner loop prints even numbers from 1 to 10 for every odd number printed by outer loop\n");

    for (i = 0; i <= 10; i++)
    {
        if (i % 2 != 0)
        {
            printf("i = %d\n", i);
            printf("--------------\n");

            for (j = 1; j <= 10; j++)
            {
                if (j % 2 == 0)
                {
                    printf("\t j = %d\n", j);
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