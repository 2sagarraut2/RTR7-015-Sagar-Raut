#include <stdio.h>

int main(void)
{

    int i;

    printf("\n\n");

    printf("Printing digits from 10 to 1:\n\n");

    i = 10;
    do
    {
        printf("\t%d\n", i);
        i--;
    } while (i >= 1);

    return 0;
}