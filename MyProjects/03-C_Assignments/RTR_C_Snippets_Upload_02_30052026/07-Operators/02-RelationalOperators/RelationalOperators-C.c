#include <stdio.h>

int main()
{

    int SR_a, SR_b, SR_result;

    // code
    printf("Enter one Integer:\n");
    scanf("%d", &SR_a);

    printf("Enter another Integer\n");
    scanf("%d", &SR_b);

    printf("If Answer = 0, It is 'FALSE'\n");
    printf("If ANswer = 1, It is 'TRUE' \n");

    SR_result = SR_a < SR_b;
    printf("(a < b) A = %d is less than B = %d \t Answer = %d\n", SR_a, SR_b, SR_result);

    SR_result = SR_a > SR_b;
    printf("(a > b) A = %d is greater than B = %d \t Answer = %d\n", SR_a, SR_b, SR_result);

    SR_result = SR_a <= SR_b;
    printf("(a <= b) A = %d is less than or equal to B = %d \t Answer = %d\n", SR_a, SR_b, SR_result);

    SR_result = SR_a >= SR_b;
    printf("(a >= b) A = %d is greater than or equal to B = %d \t Answer = %d\n", SR_a, SR_b, SR_result);

    SR_result = SR_a == SR_b;
    printf("(a == b) A = %d is equal to B = %d \t Answer = %d\n", SR_a, SR_b, SR_result);

    SR_result = SR_a != SR_b;
    printf("(a != b) A = %d is not equal to B = %d \t Answer = %d\n", SR_a, SR_b, SR_result);

    return 0;
}