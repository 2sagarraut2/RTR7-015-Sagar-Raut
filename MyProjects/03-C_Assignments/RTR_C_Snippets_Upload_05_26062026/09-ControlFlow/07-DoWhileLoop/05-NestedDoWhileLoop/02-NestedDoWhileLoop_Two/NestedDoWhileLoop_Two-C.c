#include <stdio.h>

int main(void)
{

    int i, j, k;

    printf("\n");

    i = 1;
    do
    {
        printf("i = %d \n", i);
        printf("------------");

        j = 1;
        do
        {
            printf("\t j = %d\n", j);

            k = 1;
            do
            {
                printf("\t\t k = %d\n", k);
                k++;
            } while (k <= 3);
            printf("\n\n");
            j++;
        } while (j <= 5);

        i++;
        printf("\n\n");

    } while (i <= 10);
    printf("\n\n");

    return 0;
}