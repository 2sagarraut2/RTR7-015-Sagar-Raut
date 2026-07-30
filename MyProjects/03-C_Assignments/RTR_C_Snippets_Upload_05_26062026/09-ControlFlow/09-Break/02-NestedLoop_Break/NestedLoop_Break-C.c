#include <stdio.h>

int main(void)
{

    int SR_i, SR_j;

    printf("\n\n");

    for (SR_i = 1; SR_i <= 20; SR_i++)
    {

        for (SR_j = 1; SR_j <= 20; SR_j++)
        {

            if (SR_j > SR_i)
            {
                break;
            }
            else
            {
                printf("* ");
            }
        }
        printf("\n");
    }

    printf("\n\n");

    return 0;
}