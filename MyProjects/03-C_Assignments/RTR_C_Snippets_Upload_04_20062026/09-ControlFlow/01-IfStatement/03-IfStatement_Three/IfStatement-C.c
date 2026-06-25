#include <stdio.h>

int main()
{

    // variables
    int number;

    printf("\n\n");

    printf("Enter value of num: ");
    scanf("%d", &number);

    if (number < 0)
    {
        printf("Number = %d is less than 0", number);
    }

    if ((number > 0) && (number <= 100))
    {
        printf("Number = %d is between 0 to 100", number);
    }

    if ((number > 100) && (number <= 200))
    {
        printf("Number = %d is between 100 and 200", number);
    }

    if ((number > 200) && (number <= 300))
    {
        printf("Number = %d is between 200 and 300", number);
    }

    if ((number > 300) && (number <= 400))
    {
        printf("Number = %d is between 300 and 400", number);
    }

    if ((number > 400) && (number <= 500))
    {
        printf("Number = %d is between 400 and 500", number);
    }

    if (number > 500)
    {
        printf("Number = %d is greater than 500", number);
    }

    return 0;
}