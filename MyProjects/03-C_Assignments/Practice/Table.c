#include <stdio.h>

int main()
{

    // function declaration
    int addition(int, int);

    // variable declaration
    int a = 0;
    int b = 0;
    int c = 0;

    printf("enter first number \n");
    scanf("%d", &a);

    printf("enter second number \n");
    scanf("%d", &b);

    c = addition(a, b);

    printf("addition of %d and %d is %d", a, b, c);

    return (0);
}

int addition(int a, int b)
{
    int c = a + b;

    return (c);
}