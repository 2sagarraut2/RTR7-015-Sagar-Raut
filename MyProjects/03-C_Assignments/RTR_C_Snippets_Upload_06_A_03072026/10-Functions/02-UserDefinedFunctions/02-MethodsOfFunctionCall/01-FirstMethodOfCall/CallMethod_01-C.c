#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{

    void myAddition(void);
    int mySubstraction(void);
    void myMultiplication(int, int);
    int myDivision(int, int);

    int res_sub, res_div;
    int a, b;

    myAddition();

    res_sub = mySubstraction();
    printf("\n\n");
    printf("Result of subtraction %d\n\n", res_sub);

    printf("\n\n");

    printf("Enter first number\n");
    scanf("%d", &a);

    printf("Enter second number\n");
    scanf("%d", &b);

    myMultiplication(a, b);

    printf("Enter first number\n");
    scanf("%d", &a);

    printf("Enter second number\n");
    scanf("%d", &b);

    int res_dev = myDivision(a, b);

    printf("Result of division is %d\n", res_dev);

    printf("\n---End---\n\n");
}

void myAddition(void)
{
    int a, b, sum;

    printf("\n\n");

    printf("Enter first number\n");
    scanf("%d", &a);

    printf("Enter second number\n");
    scanf("%d", &b);

    sum = a + b;

    printf("Result of adding %d and %d is %d\n\n", a, b, sum);
}

int mySubstraction(void)
{
    int a, b, subtration;

    printf("Enter first number\n");
    scanf("%d", &a);

    printf("Enter second number\n");
    scanf("%d", &b);

    subtration = a - b;

    return (subtration);
}

void myMultiplication(int a, int b)
{
    int multi;

    multi = a * b;

    printf("Multiplication of %d and %d is %d\n\n", a, b, multi);
}

int myDivision(int a, int b)
{
    int div_quo;

    if (a > b)
    {
        div_quo = a / b;
    }
    else
    {

        div_quo = a % b;
    }

    return (div_quo);
}
