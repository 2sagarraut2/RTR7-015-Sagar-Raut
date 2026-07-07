#include <stdio.h>

int main()
{

    int i, j;

    printf("\n\n");

    printf("Printing digits from 1 to 10:\n");

    for (i = 1, j = 10; i <= 10, j <= 100; i++, j = j + 10)
    {
        printf("\t%d \t %d\n", i, j);
    }

    return 0;
}