#include <stdio.h>

int main()
{
    void PrintBinaryFormOfNumber(unsigned int);

    // variables
    unsigned int SR_a;
    unsigned int SR_b;
    unsigned int SR_result;

    // code
    printf("\n\n");
    printf("Enter and Integer\n");
    scanf("%d", &SR_a);

    printf("\n\n");
    printf("Enter and Integer\n");
    scanf("%d", &SR_b);

    printf("\n\n");
    SR_result = SR_a | SR_b;

    PrintBinaryFormOfNumber(SR_a);
    PrintBinaryFormOfNumber(SR_b);
    PrintBinaryFormOfNumber(SR_result);

    return 0;
}

void PrintBinaryFormOfNumber(unsigned int decimal_number)
{
    unsigned int quotient, remainder;
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
        quotient = SR_num / 2;
        remainder = SR_num % 2;
        binary_array[SR_i] = remainder;
        SR_num = quotient;
        SR_i--;
    }

    for (SR_i = 0; SR_i < 8; SR_i++)
    {
        printf("%u", binary_array[SR_i]);
    }
}