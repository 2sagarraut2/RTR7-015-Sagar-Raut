#include <stdio.h>

int main()
{

    // func prototype
    void PrintBinaryFormOfNumber(unsigned int decimal_number);

    // variable declarations
    unsigned int SR_a;
    unsigned int SR_num_bits;
    unsigned int SR_result;

    // code
    printf("\n\n");
    printf("Enter an Integer = ");
    scanf("%u", &SR_a);

    printf("\n\n");
    printf("By How many Bits Do you want to shift A = %d to the left ? ", SR_a);
    scanf("%u", &SR_num_bits);

    printf("\n\n");
    SR_result = SR_a << SR_num_bits;
    printf("Bitwise LEFT-SHIFT by %d bits of A = %d \n gives the Result = %d (Decimal).\n\n", SR_num_bits, SR_a, SR_result);
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
