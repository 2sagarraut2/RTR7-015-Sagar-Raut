#include <stdio.h>

int main(void)
{

    int i;

    printf("\n\n");

    printf("Printing digits from 10 to 1:\n\n");

    i = 10;
    while (i >= 1)
    {
        printf("\t%d\n", i);
        i--;
    }

    return 0;
}