#include <stdio.h>

int main(void)
{

    int i;

    printf("\n\n");

    printf("Printing digits from 1 to 100:\n\n");

    i = 1;
    while (i <= 100)
    {
        printf("\t%d\n", i);
        i++;
    }

    return 0;
}