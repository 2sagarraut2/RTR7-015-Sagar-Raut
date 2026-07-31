#include <stdio.h>

int main(void)
{
    void swap(int *, int *);

    int x = 0, y = 0;

    printf("Enter first number\n");
    scanf("%d", &x);

    printf("Enter second number\n");
    scanf("%d", &y);

    printf("Values before swapping\n");
    printf("x = %d, y = %d\n\n", x, y);

    swap(&x, &y);

    printf("Values after swapping\n");
    printf("x = %d, y = %d", x, y);

    printf("\n\n--End--\n\n");
    return (0);
}

void swap(int *a, int *b)
{
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
}