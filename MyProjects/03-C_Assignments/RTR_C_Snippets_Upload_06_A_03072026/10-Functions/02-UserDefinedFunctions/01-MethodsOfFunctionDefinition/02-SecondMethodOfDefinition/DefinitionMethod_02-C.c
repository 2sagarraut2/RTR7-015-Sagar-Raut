#include <stdio.h>

int main(void)
{
    int MyAddition(void);

    int SR_result;

    printf("\n\n");

    SR_result = MyAddition();

    printf("Addition is %d", SR_result);

    printf("\n\n");

    printf("---End---\n\n");

    return 0;
}

int MyAddition(void)
{

    int a, b, SR_sum;

    printf("Enter first number\n");
    scanf("%d", &a);

    printf("Enter second number\n");
    scanf("%d", &b);

    SR_sum = a + b;

    return (SR_sum);
}