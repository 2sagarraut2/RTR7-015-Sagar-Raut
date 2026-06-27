#include <stdio.h>

int main()
{
    int a, b;
    int result;

    char option, option_division;

    printf("\n\n");

    printf("Enter first number : ");
    scanf("%d", &a);

    printf("Enter second number : ");
    scanf("%d", &b);

    printf("Enter option in character\n");
    printf("A or a for Addition:\n");
    printf("S or s for Subtraction:\n");
    printf("M or m for Multiplication\n");
    printf("D or d for Division:\n");

    printf("Enter your option : ");
    scanf(" %c", &option);

    printf("\n\n");
    switch (option)
    {
    case 'A':
    case 'a':
        result = a + b;
        printf("Addition of A = %d and B = %d gives result: %d\n", a, b, result);
        break;
    case 'S':
    case 's':
        result = a - b;
        printf("Subtraction of A = %d and B = %d gives result: %d\n", a, b, result);
        break;
    case 'M':
    case 'm':
        result = a * b;
        printf("Multiplication of A = %d and B = %d gives result: %d\n", a, b, result);
        break;
    case 'D':
    case 'd':
        printf("Enter option in character for Division\n");
        printf("Q, q or '/' for Quotient upon division\n");
        printf("R, r or '%%' for Remainder upon division\n");

        printf("Enter your option : ");
        scanf(" %c", &option_division);

        printf("\n\n");

        switch (option_division)
        {
        case 'Q':
        case 'q':
        case '/':
            if (a >= b)
            {
                result = a / b;
                printf("Quotient upon division of A = %d and B = %d gives result: %d\n", a, b, result);
            }
            else
            {
                result = b / a;
                printf("Quotient upon division of B = %d and A = %d gives result: %d\n", b, a, result);
            }
            break;

        case 'R':
        case 'r':
        case '%':
            if (a >= b)
            {
                result = a % b;
                printf("Remainder upon division of A = %d and B = %d gives result: %d\n", a, b, result);
            }
            else
            {
                result = b % a;
                printf("Remainder upon division of B = %d and A = %d gives result: %d\n", b, a, result);
            }
            break;

        default:
            printf("Invalid option entered for division %c. Please try again.\n", option_division);
            break;
        }
        break;

    default:
        printf("Invalid character entered %c. Please try again.\n", option);
        break;
    }

    printf("Switch case block executed\n");
    return 0;
}