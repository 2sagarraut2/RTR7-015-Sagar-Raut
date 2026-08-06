#include <stdio.h>

int main(void)

{

    int a = 10;
    int b = 2;
    int result = 0;

    a *= b; // a = a*b

    printf("multiplication is %d\n", a);

    // addition

    result = a + b;
    printf("addition is %d\n", result);

    // subtraction

    result = a - b;
    printf("substraction is %d\n", result);

    // multiplication

    result = a * b;
    printf("multiplication is %d\n", result);

    // division

    result = a / b;
    printf("division is %d\n", result);

    // mod - remainder %

    result = a % b;
    printf("mod is %d\n", result);

    return (0);
}