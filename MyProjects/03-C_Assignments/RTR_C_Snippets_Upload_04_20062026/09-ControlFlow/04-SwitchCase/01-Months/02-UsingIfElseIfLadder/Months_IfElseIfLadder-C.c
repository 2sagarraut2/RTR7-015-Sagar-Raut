#include <stdio.h>

int main()
{
    int num_month;

    printf("\n\n");

    printf("Enter number of month (1 to 12) : ");
    scanf("%d", &num_month);

    printf("\n\n");

    if (num_month == 1)
        printf("Month number %d is January\n\n", num_month);
    else if (num_month == 2)
        printf("Month number %d is February\n\n", num_month);
    else if (num_month == 3)
        printf("Month number %d is March\n\n", num_month);
    else if (num_month == 4)
        printf("Month number %d is April\n\n", num_month);
    else if (num_month == 5)
        printf("Month number %d is May\n\n", num_month);
    else if (num_month == 6)
        printf("Month number %d is June\n\n", num_month);
    else if (num_month == 7)
        printf("Month number %d is July\n\n", num_month);
    else if (num_month == 8)
        printf("Month number %d is August\n\n", num_month);
    else if (num_month == 9)
        printf("Month number %d is September\n\n", num_month);
    else if (num_month == 10)
        printf("Month number %d is October\n\n", num_month);
    else if (num_month == 11)
        printf("Month number %d is November\n\n", num_month);
    else if (num_month == 12)
        printf("Month number %d is December\n\n", num_month);
    else
        printf("Invalid Month number %d entered", num_month);

    printf("if else if ladder completed");

    return 0;
}