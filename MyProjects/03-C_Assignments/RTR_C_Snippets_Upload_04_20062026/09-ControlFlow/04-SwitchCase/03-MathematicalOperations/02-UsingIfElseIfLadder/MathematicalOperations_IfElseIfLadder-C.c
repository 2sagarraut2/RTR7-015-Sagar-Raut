#include <stdio.h>

int main()
{

    int a, b;
    int SR_result;

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

    if (option == 'A' || option == 'a')
    {
        SR_result = a + b;
        printf("Addition of A = %d and B = %d gives SR_result: %d\n\n", a, b, SR_result);
    }
    else if (option == 'S' || option == 's')
    {
        if (a >= b)
        {
            SR_result = a - b;
            printf("Subtraction of A = %d and B = %d gives SR_result: %d\n\n", a, b, SR_result);
        }
        else
        {
            SR_result = b - a;
            printf("Subtraction of B = %d and A = %d gives SR_result: %d\n\n", b, a, SR_result);
        }
    }
    else if (option == 'M' || option == 'm')
    {
        SR_result = a * b;
        printf("Multiplication of A = %d and B = %d gives SR_result: %d\n\n", a, b, SR_result);
    }
    else if (option == 'D' || option == 'd')
    {
        printf("Enter option in character for Division\n");
        printf("Q, q or '/' for Quotient upon division\n");
        printf("R, r or '%%' for Remainder upon division\n");

        printf("Enter your option : ");
        scanf(" %c", &option_division);

        printf("\n\n");

        if (option_division == 'Q' || option_division == 'q' || option_division == '/')
        {

            if (a >= b)
            {
                SR_result = a / b;
                printf("Quotient upon division of A = %d and B = %d gives SR_result: %d\n\n", a, b, SR_result);
            }
            else
            {
                SR_result = b / a;
                printf("Quotient upon division of B = %d and A = %d gives SR_result: %d\n\n", b, a, SR_result);
            }
        }
        else if (option_division == 'R' || option_division == 'r' || option_division == '%')
        {
            if (a >= b)
            {
                SR_result = a % b;
                printf("Remainder upon division of A = %d and B = %d gives SR_result: %d\n\n", a, b, SR_result);
            }
            else
            {
                SR_result = b % a;
                printf("Remainder upon division of B = %d and A = %d gives SR_result: %d\n\n", b, a, SR_result);
            }
        }
        else
        {
            printf("Invalid option entered for division %c. Please try again.\n\n", option_division);
        }
    }
    else
    {
        printf("Invalid option entered for mathematical operation %c. Please try again.\n\n", option);
    }

    printf("If else if ladder block executed\n");

    return 0;
}