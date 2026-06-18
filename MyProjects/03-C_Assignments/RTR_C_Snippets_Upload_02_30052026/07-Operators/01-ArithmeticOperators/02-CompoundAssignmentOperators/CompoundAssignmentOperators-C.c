#include <stdio.h>

int main()
{
    // variable declarations
    int SR_a;
    int SR_b;
    int SR_x;

    // code
    printf("\n\n");
    printf("Enter a number:\n");
    scanf("%d", &SR_a);

    printf("\n\n");
    printf("Enter another number:\n");
    scanf("%d", &SR_b);

    printf("\n\n");

    SR_x = SR_a;
    SR_a += SR_b;
    printf("Addition of %d and %d gives %d\n", SR_x, SR_b, SR_a);

    SR_x = SR_a;
    SR_a -= SR_b;
    printf("Substration of %d and %d gives %d\n", SR_x, SR_b, SR_a);

    SR_x = SR_a;
    SR_a *= SR_b;
    printf("Multiplication of %d and %d gives %d\n", SR_x, SR_b, SR_a);

    SR_x = SR_a;
    SR_a /= SR_b;
    printf("Division of %d and %d gives quotient %d\n", SR_x, SR_b, SR_a);

    SR_x = SR_a;
    SR_a %= SR_b;
    printf("Division of %d and %d gives remainder %d\n", SR_x, SR_b, SR_a);

    printf("\n\n");

    return 0;
}
