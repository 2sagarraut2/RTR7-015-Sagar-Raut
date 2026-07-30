#include <stdio.h>

int main()
{

    // function prototype
    void PrintBinaryFormOfNumber(unsigned int);

    // variable declarions
    unsigned int SR_a;
    unsigned int SR_b;
    unsigned int SR_result;

    // code
    printf("\n\n");
    printf("Enter a number = ");
    scanf("%d", &SR_a);

    printf("\n\n");
    printf("Enter another number = ");
    scanf("%d", &SR_b);

    printf("\n\n");
    SR_result = SR_a & SR_b;
    printf("Bitwise AND-ing of \nA = %d (Decimal) and B = %d (Decimal) gives SR_result %d (Decimal).\n\n", SR_a, SR_b, SR_result);

    PrintBinaryFormOfNumber(SR_a);
    PrintBinaryFormOfNumber(SR_b);
    PrintBinaryFormOfNumber(SR_result);

    return 0;
}

void PrintBinaryFormOfNumber(unsigned int decimal_number)
{
    unsigned int SR_quotient, SR_remainder;
    unsigned int SR_num;
    unsigned int binary_array[8];
    int SR_i;

    for (SR_i = 0; SR_i < 8; SR_i++)
    {
        binary_array[SR_i] = 0;
    }

    printf("\n\nThe binary form of the decimal integer %d is\t=\t", decimal_number);
    SR_num = decimal_number;

    SR_i = 7;

    while (SR_num != 0)
    {
        SR_quotient = SR_num / 2;
        SR_remainder = SR_num % 2;
        binary_array[SR_i] = SR_remainder;
        SR_num = SR_quotient;
        SR_i--;
    }

    for (SR_i = 0; SR_i < 8; SR_i++)
    {
        printf("%u", binary_array[SR_i]);
    }
}