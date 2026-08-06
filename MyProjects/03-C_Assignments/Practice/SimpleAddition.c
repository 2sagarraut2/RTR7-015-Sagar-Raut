#include <stdio.h>

int main()
{
    int addition(int, int);

    printf("Hello, World!\n\n");

    // this function perform very complex task
    // a = a + b; // 30
    // a *= b; // a = a * b // 200
    // b *= a; // b = b * a

    // if (!((a > b) && (b == c)))
    // {
    //     printf("%d is greater", a);
    // }
    // else
    // {
    //     printf("%d is smaller", a);
    // }

    int a = 10, b = 20;
    int c = 0;

    c = addition(a, b);
    printf("Addition is %d\n\n", c);

    c = addition(30, 70);
    printf("additon is %d\n\n", c);

    c = addition(1000, 2000);
    printf("additon is %d\n\n", c);

    return (0);
}

int addition(int a, int b)
{
    int c = 0;

    c = a + b;

    return c;
}