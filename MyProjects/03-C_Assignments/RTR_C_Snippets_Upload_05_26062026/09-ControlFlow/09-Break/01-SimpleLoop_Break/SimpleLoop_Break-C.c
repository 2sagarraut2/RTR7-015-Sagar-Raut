#include <stdio.h>

int main(void)
{

    int SR_i;

    char SR_ch;

    printf("\n\n");

    printf("Princting even numberd from 1 to 100 for evry user input, exitting the loop when user enters 'Q' or 'q'");

    for (SR_i = 1; SR_i <= 100; SR_i++)
    {
        if (SR_i % 2 != 0)
        {
            continue;
        }
        else
        {
            printf("\t %d \n", SR_i);
        }

        scanf(" %c", &SR_ch);

        if (SR_ch == 'q' || SR_ch == 'Q')
        {
            break;
        }
    }
    printf("exiting loop\n");

    return 0;
}