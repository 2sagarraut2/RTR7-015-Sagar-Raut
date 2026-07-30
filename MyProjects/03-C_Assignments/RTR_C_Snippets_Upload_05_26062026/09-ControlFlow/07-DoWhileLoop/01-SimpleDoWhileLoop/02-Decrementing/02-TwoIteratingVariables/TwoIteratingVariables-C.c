#include <stdio.h>

int main(void)
{

    int SR_i, SR_j;

    printf("\n\n");

    printf("Printing digits from 10 to 1 and 100 to 10:\n\n");

    SR_i = 10;
    SR_j = 100;
    do
    {
        printf("\t %d \t %d \n", SR_i, SR_j);
        SR_i--;
        SR_j = SR_j - 10;
    } while (SR_i >= 1, SR_j >= 10);

    return 0;
}