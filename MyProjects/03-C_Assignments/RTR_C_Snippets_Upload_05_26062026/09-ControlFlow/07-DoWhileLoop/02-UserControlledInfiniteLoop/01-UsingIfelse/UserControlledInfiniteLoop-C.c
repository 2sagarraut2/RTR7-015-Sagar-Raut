#include <stdio.h>

int main(void)
{

    char SR_option, SR_ch = '\0';

    printf("\n");

    printf("once the infinite loop begins, Enter 'Q' or 'q' to exit infinite loop\n\n");

    printf("Enter 'Y' or 'y' to initiate unser controlled infinite loop:");

    printf("\n");

    scanf(" %c", &SR_option);
    // printf("Y: %c", SR_option);

    if (SR_option == 'Y' || SR_option == 'y')
    {
        do
        {
            printf("in infinte loop\n");
            printf("Enter 'Q' or 'q' to exit infinite loop\n");
            scanf(" %c", &SR_ch);
            if (SR_ch == 'q' || SR_ch == 'Q')
            {
                break;
            }

        } while (1);

        printf("\n\n");
        printf("Leaving user controlled loop");
    }
    else
    {
        printf("You must press 'y' or 'Y' to initiate unser controlled infinite loop\n");
    }

    return 0;
}