#include <stdio.h>

int main()
{

    int SR_i, SR_j;

    printf("\n\n");

    printf("Printing digits from 1 to 10:\n");

    for (SR_i = 10, SR_j = 100; SR_i >= 1, SR_j >= 10; SR_i--, SR_j -= 10)
    {
        printf("\t%d \t %d\n", SR_i, SR_j);
    }

    return 0;
}