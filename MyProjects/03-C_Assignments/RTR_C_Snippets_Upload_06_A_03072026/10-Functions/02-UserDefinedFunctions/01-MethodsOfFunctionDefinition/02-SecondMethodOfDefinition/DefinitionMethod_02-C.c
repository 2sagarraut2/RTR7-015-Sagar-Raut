#include <stdio.h>

int main(void)
{
    int MyAddition(void);

    int result;

    printf("\n\n");

    result = MyAddition();

    printf("Addition is %d", result);

    printf("\n\n");

    printf("---End---\n\n");

    return 0;
}

int MyAddition(void)
{

    int a, b, sum;

    printf("Enter first number\n");
    scanf("%d", &a);

    printf("Enter second number\n");
    scanf("%d", &b);

    sum = a + b;

    return (sum);
}