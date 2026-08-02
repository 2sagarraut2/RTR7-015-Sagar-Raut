#include <stdio.h>

int main(void)
{
    char Add(int, int, int *);

    int x = -10, y = 20;
    int sum = 0;
    char ans_res = '\0';

    ans_res = Add(x, y, &sum);

    printf("Sum is %d\n", sum);
    if (ans_res == 'N')
    {
        printf("Sum is Negative\n");
    }
    else if (ans_res == 'P')
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
        return ('N');
    }
    else if (*sum > 0)
    {
        return ('P');
    }
    else
    {
        return ('Z');
    }
}