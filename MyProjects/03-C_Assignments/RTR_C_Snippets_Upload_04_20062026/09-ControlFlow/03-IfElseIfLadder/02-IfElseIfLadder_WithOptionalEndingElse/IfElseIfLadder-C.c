#include <stdio.h>

int main()
{

    // variables
    int num;

    printf("\n\n");

    printf("Enter value of num: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Num = %d is less than 0 !!!", num);
    else if ((num >= 0) && (num <= 100))
        printf("Num %d is between 0 and 100", num);

    else if ((num > 100) && (num <= 200))
        printf("Num %d is 100 between 200", num);

    else if ((num > 200) && (num <= 300))
        printf("Num %d is between 200 and 300", num);

    else if ((num > 300) && (num <= 400))
        printf("Num %d is between 300 and 400", num);

    else if ((num > 400) && (num <= 500))
        printf("Num %d is between 400 and 500", num);

    else if (num > 500)
        printf("Num %d is greater than 500", num);

    else
        printf("invalid input");

    return 0;
}