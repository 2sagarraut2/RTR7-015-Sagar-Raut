#include <stdio.h>

int main(void)
{

    int i, j, k;

    for (i = 1; i <= 10; i++)
    {
        printf("\ti = %d\n", i);
        for (j = 1; j <= 5; j++)
        {
            printf("\t\tj = %d\n", j);
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