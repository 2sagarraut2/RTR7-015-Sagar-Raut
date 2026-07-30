#include <stdio.h>

int main(void)
{

    int SR_i, SR_j, SR_c;

    for (SR_i = 1; SR_i < 64; SR_i++)
    {
        for (SR_j = 1; SR_j < 64; SR_j++)
        {

            SR_c = (((SR_i & 0x8) == 0) ^ ((SR_j & 0x8) == 0));

            if (SR_c == 0)
            {
                printf(" ");
            }

            if (SR_c == 1)
            {
                printf("* ");
            }
        }
        printf("\n\n");
    }

    return 0;
}