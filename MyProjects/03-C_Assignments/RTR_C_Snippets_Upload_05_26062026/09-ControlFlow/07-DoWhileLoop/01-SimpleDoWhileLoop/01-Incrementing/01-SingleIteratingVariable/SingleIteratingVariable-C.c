#include <stdio.h>

int main(void)
{

    int SR_i;

    printf("\n\n");

    printf("Printing digits from 1 to 100:\n\n");

    SR_i = 1;
    do
    {
        printf("\t%d\n", SR_i);
        SR_i++;
    } while (SR_i <= 100);

    return 0;
}