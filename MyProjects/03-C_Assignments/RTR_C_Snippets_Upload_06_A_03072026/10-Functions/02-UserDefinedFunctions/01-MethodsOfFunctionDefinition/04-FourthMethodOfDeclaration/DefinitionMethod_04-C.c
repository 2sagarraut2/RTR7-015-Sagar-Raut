#include <stdio.h>

int main(void)
{
    int myAddition(int, int);

    int a, b, SR_sum;

    printf("Enter first number\n");
    scanf("%d", &a);

    printf("Enter second number\n");
    scanf("%d", &b);

    SR_sum = myAddition(a, b);

    printf("Result of adding %d and %d is %d\n", a, b, SR_sum);
    printf("---End---\n\n");

    return 0;
}

int myAddition(int a, int b)
{

    return (a + b);
}