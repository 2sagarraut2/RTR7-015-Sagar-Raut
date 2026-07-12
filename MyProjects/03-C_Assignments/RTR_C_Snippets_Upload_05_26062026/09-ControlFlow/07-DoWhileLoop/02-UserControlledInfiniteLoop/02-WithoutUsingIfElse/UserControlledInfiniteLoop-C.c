#include <stdio.h>

int main(void)
{

    char SR_option, SR_ch = '\0';

    printf("\n");

    printf("once the infinite loop begins, Enter 'Q' or 'q' to exit infinite loop\n\n");

    printf("\n");

    do
    {
        do
        {
            printf("in infinte loop\n");
            scanf(" %c", &SR_ch);
        } while (SR_ch != 'Q' && SR_ch != 'q');

        printf("\n\n");
        printf("Exiting user controlled infinte loop");

        printf("\n\n");
        printf("Do you want to begin user contolled infinite loop again?...  (Press y/Y - Yes, Any other key - No) ");

        scanf(" %c", &SR_option);
    } while (SR_option == 'Y' || SR_option == 'y');

    return 0;
}