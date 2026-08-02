#include <stdio.h>

int main(int agrc, char *argv[], char *envp[])
{

    int myAddition(int, int);

    int num01, num02;

    num01 = 10;
    num02 = 20;

    printf("\n");
    printf("%d + %d = %d\n", num01, num02, myAddition(num01, num02));

    printf("\n---End---\n\n");

    return (0);
}

int myAddition(int a, int b)
{
    int add(int, int);

    return (add(a, b));
}

int add(int x, int y)
{
    return (x + y);
    printf("%d, %d", x, y);
}