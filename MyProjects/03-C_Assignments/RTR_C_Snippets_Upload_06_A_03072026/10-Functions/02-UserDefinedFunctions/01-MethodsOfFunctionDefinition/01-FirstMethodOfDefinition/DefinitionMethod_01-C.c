#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{

    void myAddition(void);

    myAddition();

    printf("---End---\n\n");

    return (0);
}

void myAddition(void)
{

    int a, b, SR_sum;

    printf("\n");

    printf("Enter first number\n");
    scanf("%d", &a);

    printf("Enter second number\n");
    scanf("%d", &b);

    SR_sum = a + b;

    printf("\n\n");

    printf("Sum of adding %d and %d is %d\n\n", a, b, SR_sum);
}