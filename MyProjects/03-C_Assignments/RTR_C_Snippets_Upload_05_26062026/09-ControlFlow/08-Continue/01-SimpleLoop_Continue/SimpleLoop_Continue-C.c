#include <stdio.h>

int main(void)
{

    int i;

    printf("\n");

    printf("printing even nunbers from 0 to 100\n");

    for (i = 0; i <= 100; i++)
    {
        if (i % 2 != 0)
        {
            continue;
        }
        else
        {
            printf("\t%d\n", i);
        }
    }

    return 0;
}