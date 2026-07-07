#include <stdio.h>

int main(void)
{

    int i;

    printf("\n\n");

    printf("Printing digits from 1 to 100:\n\n");

    i = 1;
    do
    {
        printf("\t%d\n", i);
        i++;
    } while (i <= 100);

    return 0;
}