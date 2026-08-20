#include <stdio.h>
int main()
{
    int addition(int, int);
    int a = 10;
    int b = 20;
    int c = 0;

    c = addition(a, b);

    printf("addition is %d", c);

    return (0);
}

int addition(int a, int b)
{
    int c = 0;
    c = a + b;
    // printf("addition is %d", c);
    return (c);
}
