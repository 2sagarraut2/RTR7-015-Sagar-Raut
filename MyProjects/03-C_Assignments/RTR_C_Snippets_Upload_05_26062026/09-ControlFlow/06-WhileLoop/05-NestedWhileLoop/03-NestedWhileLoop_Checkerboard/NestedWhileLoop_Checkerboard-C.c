#include <stdio.h>

int main(void)
{

    int SR_i, SR_j, SR_c;

    SR_i = 0;
    while (SR_i < 64)
    {
        SR_j = 0;
        while (SR_j < 64)
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
            SR_j++;
        }
        SR_i++;
        printf("\n\n");
    }

    return 0;
}