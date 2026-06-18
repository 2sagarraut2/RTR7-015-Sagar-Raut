#include <stdio.h>

int main()
{
    int SR_a, SR_b, SR_c, SR_result;

    printf("\n");

    printf("Enter first Integer\n");
    scanf("%d", &SR_a);

    printf("Enter second Integer\n");
    scanf("%d", &SR_b);

    printf("Enter third Integer\n");
    scanf("%d", &SR_c);

    printf("If Answer = 0, It is 'FALSE'\n");
    printf("If ANswer = 1, It is 'TRUE' \n\n");

    SR_result = SR_a <= SR_b && SR_b != SR_c;
    printf("Only if both conditions are TRUE then answer will be TRUE else FALSE\n\n");
    printf("A = %d is less than or equal to B = %d and B = %d not equal to C = %d\t Answer = %d\n\n", SR_a, SR_b, SR_b, SR_c, SR_result);

    SR_result = SR_b >= SR_a || SR_a == SR_c;
    printf("If any condition is TRUE then answer will be TRUE or both FALSE then false\n\n");
    printf("Either B = %d is greater than or equal to A = %d OR A = %d is equal equal to C = %d\t Answer = %d\n\n", SR_b, SR_a, SR_a, SR_c, SR_result);

    SR_result = !SR_a;
    printf("A = %d and logical not operator gives Result = %d\n\n", SR_a, SR_result);

    SR_result = !SR_b;
    printf("B = %d and logical not operator gives Result = %d\n\n", SR_b, SR_result);

    SR_result = !SR_c;
    printf("C = %d and logical not operator gives Result = %d\n\n", SR_c, SR_result);

    SR_result = !(SR_a <= SR_b) && !(SR_b != SR_c);
    printf("Using logical not on (a <= b) and also on (b != c) and then && them afterwards gives Result = %d\n\n", SR_result);

    SR_result = !((SR_b >= SR_a) || (SR_a == SR_c));
    printf("Using logical not on entire logical expression (b >= a) || (a == c) gives Result = %d\n\n", SR_result);

    return 0;
}
