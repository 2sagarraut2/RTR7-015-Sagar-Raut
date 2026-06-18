#include <stdio.h>

int main()
{
    int SR_a = 5;
    int SR_b = 15;

    printf("\n");
    printf("A = %d\n", SR_a);   // 5
    printf("A = %d\n", SR_a++); // 5
    printf("A = %d\n", SR_a);   // 6
    printf("A = %d\n", ++SR_a); // 7

    printf("\n");
    printf("B = %d\n", SR_b);   // 15
    printf("B = %d\n", SR_b--); // 15
    printf("B = %d\n", SR_b);   // 14
    printf("B = %d\n", --SR_b); // 13

    return 0;
}
