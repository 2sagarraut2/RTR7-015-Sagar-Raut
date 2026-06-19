#include <stdio.h>

int main()
{

    // func prototype
    void PrintBinaryFormOfNumber(unsigned int decimal_number);

    // varibale declarations
    unsigned int SR_a;
    unsigned int SR_result;

    // code
    printf("\n\n");
    printf("Enter an Integer\n");
    scanf("%u", &SR_a);

    printf("\n\n");
    SR_result = ~SR_a;

    printf("Bitwise Complementing of \nA = %d (Decimal) gives result %d (Decimal).\n\n", SR_a, SR_result);

    PrintBinaryFormOfNumber(SR_a);
    PrintBinaryFormOfNumber(SR_result);

    return 0;
}

void PrintBinaryFormOfNumber(unsigned int decimal_number)
{
    unsigned int quotient, remainder;
    unsigned int num;
    unsigned int binary_array[8];
    int i;

    for (i = 0; i < 8; i++)
    {
        binary_array[i] = 0;
    }

    printf("\n\nThe binary form of the decimal integer %d is\t=\t", decimal_number);
    num = decimal_number;

    i = 7;

    while (num != 0)
    {
        quotient = num / 2;
        remainder = num % 2;
        binary_array[i] = remainder;
        num = quotient;
        i--;
    }

    for (i = 0; i < 8; i++)
    {
        printf("%u", binary_array[i]);
    }
}
