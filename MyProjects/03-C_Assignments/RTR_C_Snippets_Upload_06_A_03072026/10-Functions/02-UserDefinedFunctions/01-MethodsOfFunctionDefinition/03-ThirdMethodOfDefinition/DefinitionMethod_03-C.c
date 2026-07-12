#include <stdio.h>

int main(void)
{
    void MyAddition(int, int);

    int a, b;

    printf("Enter first number\n");
    scanf("%d", &a);

    printf("Enter second number\n");
    scanf("%d", &b);

    MyAddition(a, b);

    printf("\n");

    printf("---End---\n\n");

    return 0;
}

void MyAddition(int a, int b)
{
    printf("Sum of addting %d and %d is %d", a, b, a + b);
}