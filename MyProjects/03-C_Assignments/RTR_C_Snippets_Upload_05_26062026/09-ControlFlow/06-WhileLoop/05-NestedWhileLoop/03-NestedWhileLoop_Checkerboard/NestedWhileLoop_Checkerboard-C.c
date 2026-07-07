#include <stdio.h>

int main(void)
{

    int i, j, c;

    i = 0;
    while (i < 64)
    {
        j = 0;
        while (j < 64)
        {

            c = (((i & 0x8) == 0) ^ ((j & 0x8) == 0));

            if (c == 0)
            {
                printf(" ");
            }

            if (c == 1)
            {
                printf("* ");
            }
            j++;
        }
        i++;
        printf("\n\n");
    }

    return 0;
}