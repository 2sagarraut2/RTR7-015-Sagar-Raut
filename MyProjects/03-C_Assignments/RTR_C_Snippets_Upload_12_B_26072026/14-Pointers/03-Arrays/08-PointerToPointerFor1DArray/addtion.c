#include <stdio.h>

int main(void)
{
    void add(int, int, int *);

    int res = 0;
    int x = 10, y = 15;

    add(x, y, &res);

    printf("Addition of %d and %d = %d\n", x, y, res);

    printf("\n\n--End--\n\n");
    return (0);
}

void add(int a, int b, int *sum)
{
    *sum = a + b;
}