#include <stdio.h>

enum
{
    NEGATIVE = -1,
    ZERO,
    POSITIVE
};

int main(void)
{
    char Add(int, int, int *);

    int x = 0, y = 0;
    int sum = 0;
    char ans_res = '\0';

    printf("Enter first number\n");
    scanf("%d", &x);

    printf("Enter second number\n");
    scanf("%d", &y);

    ans_res = Add(x, y, &sum);

    printf("Sum is %d\n", sum);
    if (ans_res == NEGATIVE)
    {
        printf("Sum is Negative\n");
    }
    else if (ans_res == POSITIVE)
    {
        printf("Sum is Positive\n");
    }
    else
    {
        printf("Sum is Zero\n");
    }

    printf("\n\n--End--\n\n");
    return (0);
}

char Add(int a, int b, int *sum)
{
    *sum = a + b;

    if (*sum < 0)
    {
        return (NEGATIVE);
    }
    else if (*sum > 0)
    {
        return (POSITIVE);
    }
    else
    {
        return (ZERO);
    }
}