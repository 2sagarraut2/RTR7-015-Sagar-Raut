#include <stdio.h>

int main(void)
{

    int SR_i, SR_j, SR_c;

    SR_i = 0;
    do
    {
        SR_j = 0;
        do
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
        } while (SR_j < 64);
        SR_i++;
        printf("\n\n");
    } while (SR_i < 64);

    return 0;
}