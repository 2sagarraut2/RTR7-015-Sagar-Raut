#include <stdio.h>

int main(void)
{
    // variable declarations
    // SR - SAGAR RAUT
    int SR_a;
    int SR_b;
    int SR_result;

    // code
    printf("\n");
    printf("ENter a number\n");
    scanf("%d", &SR_a);

    printf("Enter another number\n");
    scanf("%d", &SR_b);

    printf("\n\n");

    SR_result = SR_a + SR_b;
    printf("Addition of A = %d and B = %d gives %d.\n", SR_a, SR_b, SR_result);

    SR_result = SR_a - SR_b;
    printf("Substration od A = %d and B = %d gives %d.\n", SR_a, SR_b, SR_result);

    SR_result = SR_a * SR_b;
    printf("Multiplication of A = %d and B = %d gives %d.\n", SR_a, SR_b, SR_result);

    SR_result = SR_a / SR_b;
    printf("Division of A = %d and B = %d gives quotient %d.\n", SR_a, SR_b, SR_result);

    SR_result = SR_a % SR_b;
    printf("Division of A = %d and B = %d gives remainder %d.\n", SR_a, SR_b, SR_result);

    return 0;
}
