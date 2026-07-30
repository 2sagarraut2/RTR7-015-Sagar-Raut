#include <stdio.h>

int main(void)
{

    int SR_i;

    printf("\n");

    printf("printing even nunbers from 0 to 100\n");

    for (SR_i = 0; SR_i <= 100; SR_i++)
    {
        if (SR_i % 2 != 0)
        {
            continue;
        }
        else
        {
            printf("\t%d\n", SR_i);
        }
    }

    return 0;
}