#include <stdio.h>

int main(void)
{

    int SR_i;

    printf("\n\n");

    printf("Printing digits from 10 to 1:\n\n");

    SR_i = 10;
    do
    {
        printf("\t%d\n", SR_i);
        SR_i--;
    } while (SR_i >= 1);

    return 0;
}