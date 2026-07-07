#include <stdio.h>

int main(void)
{

    int i;

    char ch;

    printf("\n\n");

    printf("Princting even numberd from 1 to 100 for evry user input, exitting the loop when user enters 'Q' or 'q'");

    for (i = 1; i <= 100; i++)
    {
        if (i % 2 != 0)
        {
            continue;
        }
        else
        {
            printf("\t %d \n", i);
        }

        scanf(" %c", &ch);

        if (ch == 'q' || ch == 'Q')
        {
            break;
        }
    }
    printf("exiting loop\n");

    return 0;
}