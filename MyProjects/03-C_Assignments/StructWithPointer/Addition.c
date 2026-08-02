#include <stdio.h>

int main()
{
    int Addition(int, int);
    int a = 0, b = 0;
    int result = 0;

    // a = 10;
    // b = 20;

    printf("Enter one \t number\n");
    scanf("%d", &a);

    printf("Enter second number\n");
    scanf("%d", &b);

    result = Addition(a, b);

    // this line prints addition
    printf("Addition of %d and %d is %d", a, b, result);

    printf("\n");
}
